#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int flag,a[4];
int ansc(int d,int aa,int bb)
{
    if(d==1) return bb+aa;
    else if(d==2) return bb-aa;
    else if(d==3) return bb*aa;
    else if(d==4&&aa!=0&&bb%aa==0) return bb/aa;
    else return 100000;
}
int clc()
{
    int ans[4];
    ans[0]=a[0];
    for(int i=1;i<=4;i++)
    {
        ans[1]=ansc(i,a[1],ans[0]);
        for(int j=1;j<=4;j++)
        {
            ans[2]=ansc(j,a[2],ans[1]);
            for(int k=1;k<=4;k++)
            {
                ans[3]=ansc(k,a[3],ans[2]);
                if(ans[3]==24) return 1;
            }
        }
    }
    return 0;       
}
int main()
{
    char c[4];
    int i,len;
    while(~scanf("%s",c))
    {
        len=strlen(c);
        if(len==2) a[0]=10;
        else if(c[0]=='A') a[0]=1;
        else if(c[0]=='J') a[0]=11;
        else if(c[0]=='Q') a[0]=12;
        else if(c[0]=='K') a[0]=13;
        else a[0]=c[0]-'0';
        for(i=1;i<4;i++)
        {
            scanf("%s",c);
            len=strlen(c);
            if(len==2) a[i]=10;
            else if(c[0]=='A') a[i]=1;
            else if(c[0]=='J') a[i]=11;
            else if(c[0]=='Q') a[i]=12;
            else if(c[0]=='K') a[i]=13;
            else a[i]=c[0]-'0';
        }
        flag=0;
        sort(a,a+4);
        flag=clc();
        while(next_permutation(a,a+4))
        {
            if(flag) break;
            flag=clc();
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}