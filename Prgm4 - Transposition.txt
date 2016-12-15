#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
    cout<<"Enter the depth:\t";
    int d;
    cin>>d;
    cout<<"Enter the length of key:\t";
    int l1;
    cin>>l1;
    int seq[l1];
    cout<<"Enter key sequence:\t";
    for(int i=0;i<l1;i++)
    {
        cin>>seq[i];
    }
    cout<<"Enter string without spaces:\n";
    char plain[100];
    cin>>plain;
    //Modifying Input
    int len = strlen(plain);
    if(len%l1!=0)
    {
        while(len%l1!=0)
            plain[len++] = 'x';
        plain[len] = '\0';
        cout<<"Extra Char:\t"<<'x'<<endl;
        cout<<"Modified plaintext:\t"<<plain<<endl;
    }
    int order[l1];
    for(int i=1;i<=l1;i++)
    {
        for(int j=0;j<l1;j++)
        {
            if(seq[j]==i)
                order[i-1] = j;
        }
    }
    //Encryption
    cout<<"\n\t\tENCRYPTION\n";
    int d1 = d;
    int r = len / l1;
    char p[r][l1];
    while(d1>0)
    {
        cout<<"\t\tTRANSPOSITION "<<(d-d1+1)<<endl;
        int k=0;

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<l1;j++)
            {
                p[i][j]=plain[k++];
            }
        }
        cout<<"The matrix arrangement is :\n";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<l1;j++)
                cout<<p[i][j]<<" ";
            cout<<endl;
        }
        k=0;
        for(int i=0;i<l1;i++)
        {
            for(int j=0;j<r;j++)
            {
                plain[k++] = p[j][order[i]];
            }
        }
        cout<<"\nThe encrypted text is:\t"<<plain<<endl;
        d1=d1-1;
    }
    //Decryption
    cout<<"\n\t\tDECRYPTION\n";
    while(d>0)
    {
        cout<<"\t\tTRANSPOSITION "<<d<<endl;
        int k=0;
        for(int i=0;i<l1;i++)
        {
            for(int j=0;j<r;j++)
            {
                p[j][order[i]] = plain[k++];
            }
        }
        cout<<"The matrix arrangement is :\n";
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<l1;j++)
                cout<<p[i][j]<<" ";
            cout<<endl;
        }
        k=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<l1;j++)
            {
                plain[k++]= p[i][j];
            }
        }
        cout<<"\nThe decrypted text is:\t"<<plain<<endl;
        d=d-1;
    }
    return 0;
}
