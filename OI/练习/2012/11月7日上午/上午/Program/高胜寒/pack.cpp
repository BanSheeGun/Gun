#include<cstdio>
#include<cstring>
int a[111],b[111],c[111],t[111],f[2222],g[2222];
void cmax(int &a,int b){
    if (b>a) a=b;
}
int main(){
    int n,m,i,j,k,ans;
    bool pd;
    freopen("pack.in","r",stdin);
    freopen("pack.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++){
        scanf("%d%d%d",t+i,a+i,b+i);
        if (t[i]==2) scanf("%d",c+i);
    }
    pd=true;
    ans=0;
    if (m>=500){
        pd=false;
        ans=0;
        for (i=0;i<n;i++){
            if (t[i]==1 && a[i]){
                pd=true;
                cmax(ans,m*m*a[i]-m*b[i]);
            }
        }
        if (pd){
            printf("%d\n",ans);
            return 0;
        }
    }
    memset(f,0,sizeof f);
    for (i=0;i<n;i++){
        if (t[i]==2){
            memcpy(g,f,sizeof g);
            for (j=b[i];j<=m;j++)
                for (k=1;k<=j/b[i] && k<=c[i];k++)
                    cmax(g[j],f[j-k*b[i]]+k*a[i]);
            memcpy(f,g,sizeof f);
        } else
        if (t[i]==3){
            for (j=b[i];j<=m;j++)
                cmax(f[j],f[j-b[i]]+a[i]);
        } else
        if (pd){
            memcpy(g,f,sizeof g);
            for (j=1;j<=m;j++)
                for (k=1;k<=j;k++)
                    cmax(g[j],f[j-k]+k*k*a[i]-k*b[i]);
            memcpy(f,g,sizeof f);
        }
        for (j=0;j<=m;j++)
            cmax(ans,f[j]);
    }
    printf("%d\n",ans);
    return 0;
}
