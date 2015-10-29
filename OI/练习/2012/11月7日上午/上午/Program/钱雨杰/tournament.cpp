#include<cstdio>
int n,m,x,y,num[55],a[55][55],q[555],l,r;

int main(){
    freopen("tournament.in","r",stdin);
    freopen("tournament.out","w",stdout);
    scanf("%d",&n);
    m=(n-1)*n/2-1;
    for (int i=1; i<=m; i++)
      {
        scanf("%d%d",&x,&y);
        a[x][y]=1;
        num[x]++; num[y]++;
      }
    x=0; y=0;
    for (int i=1; i<=n; i++)
        if (num[i]!=n-1) {
                           if (x==0) x=i;
                                else y=i;
                         }
    l=1; r=0;
    for (int i=1; i<=n; i++)
        if (a[x][i]==1) q[++r]=i;
    while (l<=r)
      {
        for (int i=1; i<=n; i++)
            if (a[q[l]][i]==1 && a[x][i]==0)
              {
                r++; q[r]=i; a[x][i]=1;
              }
        l++;
      }
    if (a[x][y]==1) printf("%d %d\n",x,y);
               else printf("%d %d\n",y,x);
    return 0;
}
