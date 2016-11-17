#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char msg[20],key[20],text[20],text2[20];
	cout<<"Enter the message:"<<endl;
	cin>>msg;
	cout<<"Enter the keyword:"<<endl;
	cin>>key;
	
	char msg2[strlen(key)*2];
	//char cip[strlen(key)*2];
	char c[5][5]={0};
	int a1[26]={0};
	int l=0,n=0;
	char temp[25]={0};
	int p=0;
	
	//to mark the position of letters as 1 if they are present in key
	for(int i=0;i<strlen(key);i++)
	{	
		if(a1[key[i]-'a']==0)
		{
			temp[n++]=key[i];
			a1[key[i]-'a']=1;	
		}
	}
	
	for(int i=0;i<26;i++)
	{
		if(i==9)
			continue;
		if(a1[i]==0)
		{
			temp[n++]=i+'a';
		}
	}
	
	//case 1
	int i=0,j=0;
	while(i<strlen(msg))//;i+=2)
	{
		if(msg[i]!=msg[i+1])
		{
			msg2[j++]=msg[i];
			msg2[j++]=msg[i+1];
			i=i+2;
		}
		else if(msg[i]==msg[i+1])
		{
			msg2[j++]=msg[i];
			msg2[j++]='x';
			i=i+1;
		}
	}
	if(strlen(msg2)%2!=0)
		msg2[j+1]='x';
	
	int m=0;
	
	//assigning the characters to matrix and printing the matrix
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			c[i][j]=temp[m++];
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"Encryption"<<endl;
	int k=0,i1=0,i2=0,j2=0,j1=0;
	p=0;
	//to append x if there is odd no of elements
	if(strlen(msg2)%2!=0){
		for(i=0;msg2[i]!='\0';i++);
		msg2[i++]='x';
		msg2[i]='\0';
	}
	
	while(k<=strlen(msg2)-1)
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(c[i][j]==msg2[k])
				{
					i1=i;
					j1=j;
				}
				if(c[i][j]==msg2[k+1])	
				{
					i2=i;
					j2=j;
				}
			}
					
		}
		//case 2:if both the characters are in the same row
		if(i1==i2)
		{
			//cip[p++]=c[i1][(j1+1)%5];
			//cip[p++]=c[i2][(j2+1)%5];
			text[k]=c[i1][(j1+1)%5];
			text[k+1]=c[i2][(j2+1)%5];
			cout<<msg2[k]<<msg2[k+1]<<"-->"<<text[k]<<text[k+1]<<endl;
			k=k+2;
		}
		//case 3:if both the characters are in the same column
		else if(j1==j2)
		{
			//cip[p++]=c[(i1+1)%5][j1];
			//cip[p++]=c[(i2+1)%5][j2];
			text[k]=c[(i1+1)%5][j1];
			text[k+1]=c[(i2+1)%5][j2];
			cout<<msg2[k]<<msg2[k+1]<<"-->"<<text[k]<<text[k+1]<<endl;
			k=k+2;
		}
		//case 4:if not in same row or same column
		else
		{
			//cip[p++]=c[i1][j2];
			//cip[p++]=c[i2][j1];
			text[k]=c[i1][j2];
			text[k+1]=c[i2][j1];
			cout<<msg2[k]<<msg2[k+1]<<"-->"<<text[k]<<text[k+1]<<endl;
			k=k+2;
		}
	}
	text[k]='\0';
	cout<<"Encryption"<<endl;
	cout<<"Encrypted string is: "<<text;
	int h=0;
	/*while(h<(strlen(msg2)))
		cout<<text[h++];*/
	cout<<endl;
	
	cout<<"Decryption"<<endl;
	k=0;
	while(k<=strlen(msg2)-1)
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{
				if(c[i][j]==text[k])
				{
					i1=i;
					j1=j;
				}
				if(c[i][j]==text[k+1])	
				{
					i2=i;
					j2=j;
				}
			}
					
		}
		//case 2:if both the characters are in the same row
		if(i1==i2)
		{
			if(j1==0) j1=5;
			if(j2==0) j2=5;
			//cip[p++]=c[i1][(j1-1)%5];
			//cip[p++]=c[i2][(j2-1)%5];
			text2[k]=c[i1][(j1-1)%5];
			text2[k+1]=c[i2][(j2-1)%5];
			cout<<text[k]<<text[k+1]<<"-->"<<text2[k]<<text2[k+1]<<endl;
			k=k+2;
		}
		//case 3:if both the characters are in the same column
		else if(j1==j2)
		{	
			if(i1==0) i1=5;
			if(i2==0) i2=5;
			//cip[p++]=c[(i1-1)%5][j1];
			//cip[p++]=c[(i2-1)%5][j2];
			text2[k]=c[(i1-1)%5][j1];
			text2[k+1]=c[(i2-1)%5][j2];
			cout<<text[k]<<text[k+1]<<"-->"<<text2[k]<<text2[k+1]<<endl;
			k=k+2;
		}
		//case 4:if not in same row or same column
		else
		{
			//cip[p++]=c[i1][j2];
			//cip[p++]=c[i2][j1];
			text2[k]=c[i1][j2];
			text2[k+1]=c[i2][j1];
			cout<<text[k]<<text[k+1]<<"-->"<<text2[k]<<text2[k+1]<<endl;
			k=k+2;
		}
	}
	text2[k]='\0';
	cout<<"Decrypted sting is: "<<text2;
	h=0;
	/*while(h<(strlen(msg2))){
		//if(text2[h]=='x')
			//h++;
		//else
		cout<<text2[h++];
	}*/
	cout<<endl;
	
}
