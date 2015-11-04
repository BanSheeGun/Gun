#include<cstdio>
#include<cstring>
int n,m,x,n1,n2,n3,a1[111],a2[111],a3[111],b1[111],b2[111],b3[111],c2[111];
int f[2222],g[2222],h[2222];

int main(){
    freopen("pack.in","r",stdin);
    freopen("pack.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++)
      {
        scanf("%d",&x);
        if (x==1) {
                    n1++;
                    scanf("%d%d",&a1[n1],&b1[n1]);
                  }
        if (x==2) {
                    n2++;
                    scanf("%d%d%d",&a2[n2],&b2[n2],&c2[n2]);
                  }
        if (x==3) {
                    n3++;
                    scanf("%d%d",&a3[n3],&b3[n3]);
                  }
      }
    for (int i=0; i<=m; i++)
      {
        for (int j=1; j<=n3; j++)
            if (i+b3[j]<=m && f[i]+a3[j]>f[i+b3[j]])
               f[i+b3[j]]=f[i]+a3[j];
        if (i>0) if (f[i-1]>f[i]) f[i]=f[i-1];
      }
    for (int i=1; i<=n2; i++)
      {
        memcpy(h,g,sizeof g);
        for (int j=1; j<=c2[i]; j++)
            for (int k=0; k<=m; k++)
              {
                if (k+b2[i]*j>m) break;
                if (g[k]+a2[i]*j>h[k+b2[i]*j])
                   h[k+b2[i]*j]=g[k]+a2[i]*j;
                //if (k>0) if (g[k-1]>g[k]) g[k]=g[k-1];
              }
        memcpy(g,h,sizeof h);
      }
    for (int i=0; i<=m; i++)
        for (int j=0; j<=m; j++)
          {
            if (i+j>m) break;
            if (g[i]+f[j]>g[i+j]) g[i+j]=g[i]+f[j];
          }
    for (int i=1; i<=n1; i++)
        for (int j=0; j<=m; j++)
            for (int k=1; k<=m; k++)
                if (j+k>m) break;
                      else if (g[j]+a1[i]*k*k-b1[i]*k>g[j+k]) g[j+k]=g[j]+a1[i]*k*k-b1[i]*k;
    printf("%d\n",g[m]);
    return 0;
}
