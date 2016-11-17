#include<stdio.h>
#include<netinet/in.h>
#include<time.h>
#include<string.h>
int generate(int xa,int q,int num)
{
	int i,ret=1;
	for(i=0;i<xa;i++)
	{
		ret=ret*num;
		ret=ret%q;
	}
	return ret;
}
void main()
{
	int q,alpha;
	int xa,ya=1,yb,k=1,i,port,sockfd,len,p,c,ch;
	char ser[20];
	struct sockaddr_in server;
	srand(time(NULL));
	printf("Enter the values of q and alpha: ");
	scanf("%d%d",&q,&alpha);
	xa = rand()%q;
	ya = generate(xa,q,alpha);				//ya = (alpha ^ xa) mod q
	printf("Private Key : %d \t Public Key : %d\n",xa,ya);
	
	printf("Enter\nO for local host\n1 for IP adress\n");
	scanf("%d",&ch);
	
	if(ch==0)
		strcpy(ser,"127.0.0.1");
	
	else
	{
	printf("Enter the USER B IP address: ");
	scanf("%s",ser);
	}
	printf("Enter the port number: ");
	scanf("%d",&port);
	sockfd = socket(AF_INET,SOCK_STREAM,0);			//SOCKET
	server.sin_port = htons(port);
	server.sin_addr.s_addr = inet_addr(ser);
	server.sin_family = AF_INET;
	
	connect(sockfd,(struct sockaddr*)&server,sizeof(server));//CONNECT
	printf("Connected... Sending public key...\n");
	send(sockfd,&ya,sizeof(ya),0);				//SEND ya
	
	printf("Waiting to receive USER B's public key...\n");
	recv(sockfd,&yb,sizeof(yb),0);				//RECV yb
	
	printf("USER B's public key received: %d\nCalculating shared key....",yb);
	k=generate(xa,q,yb);					//k = (yb ^ xa) mod q
	printf("The Shared Key is : %d \n",k);
	
	printf("Enter the message to be sent: ");
	scanf("%d",&p);
	c=p^k;
	
	printf("The encrypted message is: %d\nSending the encrypted message...\n",c);
	send(sockfd,&c,sizeof(c),0);				//SEND cipher
	close(sockfd);
}
