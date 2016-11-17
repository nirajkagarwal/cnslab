#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char key[26]={'t','h','e','q','u','i','c','k','b','r','o','w','n','f','x','j','m','p','s','v','l','a','z','y','d','g'};
int alpha[26] = {0};
void cryptanalysis(int count)
{
	int i;
	float freq;
	printf("\nFreq\tPlain\tCipher\n");
	for(i=0;i<26;i++)
	{
		freq = (float)alpha[i]/count;
		printf("%f \t%c \t%c\n",freq,('a'+ i),key[i]);
	}
}
int main()
{
	int i, count=0;
	FILE *fp1, *fp2; 
	char c;
	fp1 = fopen("plaintext.txt","r");
	fp2 = fopen("ciphertext.txt","w");
	while((c=fgetc(fp1))!=EOF)
	{
		if(isalpha(c))
		{
			alpha[c-'a']++;
			putc(key[c-'a'],fp2);
			count++;
		}
	}
	printf("\n The total number of characters are:\t%d\n",count);
	close(fp1);
	close(fp2);
	cryptanalysis(count);
}
