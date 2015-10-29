#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n,x,y,;
int g[100][100];
int main()
{
    freopen("tournament.in","r",stdin);
    freopen("tournament.out","w",stdout);
    memset(g,0,sizeof(g));
    scanf("%d",&n);
    for (int i=0; i<(n*(n-1)/2-1); i++)
    {
        scanf("%d%d",&x,&y);
        g[x][y]=1;
        g[y][x]=-1;
        g[x][0]+=1;
        g[y][0]+=1;
    }
    x=y=0;
/*
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
*/
    for (int i=1; i<=n; i++)
        if (g[i][0]==n-2)
           {x=i;break;}
    for (int i=x+1; i<=n; i++)
        if (g[i][0]==n-2)
           {y=i;break;}
//   printf("%d %d",x,y);
    for (int i=1; i<=n; i++)
    {
        if (g[x][i]==g[i][y])
        {
           if (g[x][i]==-1) printf("%d %d\n",y,x);
           else printf("%d %d\n",x,y);
           break;
        }
    }
//    system("pause");
    return 0;
}
