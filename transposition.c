#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i,j,d,d1,k,l,r,len;
	int seq[10];
	char msg[100];
	char plain[20][20], cipher[100];
	printf("Enter the length of key sequence:\t");
	scanf("%d",&l);
	printf("Enter the key sequence:\n");
	for(i=0;i<l;i++)
		scanf("%d",&seq[i]);
	getchar();
	printf("Enter the message without spaces:\n");
	scanf("%s",&msg);
	len = strlen(msg);
	r = len/l;
	i = len-(l*r);
	while(i!=0)
	{
		msg[len] = 'x';
		len = len+1;
		i--;
	}
	r=r+1;
	k=0;
	printf("The arrangement:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<l;j++)
		{
			plain[i][j] = msg[k++];
			printf("%c ",plain[i][j]);
		}
		printf("\n");
	}
	k=0;
	printf("\nEncryption\n");
	for(i=0;i<l;i++)
	{
		for(j=0;j<r;j++)
		{
			cipher[k++] = plain[j][seq[i]-1];
		}
	}
	printf("The arrangement:\n");
	for(i=0;i<k;i++)
	{
		printf("%c",cipher[i]);
	}
	printf("\n");
	k=0;
	printf("\nDecryption\n");
	for(i=0;i<l;i++)
	{
		for(j=0;j<r;j++)
		{
			plain[j][seq[i]-1] = cipher[k++];
		}
	}
	printf("The arrangement:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<l;j++)
		{
			printf("%c",plain[i][j]);
		}
	}
}
