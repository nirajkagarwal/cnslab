#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int gcd(long int m, long int n)
{
    if ( m==0 )
        return n;
    return gcd (n%m, m);
}
void test(unsigned long long int n)
{
	unsigned long long int z=n-1;
	unsigned long long int k=0,q=1,i,j,w,x,y,a;
	if(n==1||n==0)
	{
		printf("\n%llu is not Prime\n",n);
		return;
	}
	while(z%2==0)
	{
		z =z/2;
		k++;
	}
	q=z;				//
	a = rand()%(n-1);
	if(a==1)	a=2;
	x=1;
	for(i=1;i<=q;i++)
	{
		x = (x*a)%n;		//a^q mod n
	}
	if(x==1)
	{
		printf("%llu is inconclusive\n",n);
		return;
	}
	for(i=0;i<k;i++)
	{
		x=1,y=1;
		for(j=1;j<=i;j++)
		{
			x = x*2;	//2^i
		}
		x = x*q;		//x = q.2^i
		for(w=1;w<=x;w++)
		{
			y = (y*a)%n;	//a^x mod n
		}
		if(y==(n-1))		//a^x mod n == n-1
		{
			printf("%llu can be prime\n",n);
			return ;
		}
	}
	printf("%llu is composite\n",n);
}
void BBS()
{
	int p,q,no,i;
	unsigned long long int n,s,res=0,x;
	srand(time(NULL));
	printf("Enter any 2 prime number (3 mod 4):\n");
	do{
		p = rand()%10000;
	}while((p%4)!=3);
	do{
		q = rand()%10000;
	}while((q%4)!=3);
	printf("\np=%d\n",p);
	printf("q=%d\n",q);
	n = p*q;
	printf("Enter the number of bits required:\t");
	scanf("%d",&no);
	do{
		s = rand()%10000;
	}while((gcd(s,n)!=1)&&(s==1));
	x = (s*s)%n;
	for(i=1;i<=no;i++)
	{
		x = (x*x)%n;
		printf("%d ",(x%2));
		res = (res<<1)|(x&1);
	}
	printf("\n");
	printf("Random Number:\t%llu\n",res);
	printf("Testing for Primality:\n");
	test(res);
}
int main()
{
	BBS();
	return 0;
}
