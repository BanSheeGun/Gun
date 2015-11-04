#include<iostream>
#include<memory.h>
using namespace std;
int main(){
    int t,tt;
    scanf("%d",&t);
    for (tt=1;tt<=t;++tt){
        int n,k,i,j,a,b,e;
        long long f[41];
        memset(f,0,sizeof(f));
        f[0]=1;
        scanf("%d%d",&n,&k);
        for (j=1;j<=k;++j){
            scanf("%d%d",&a,&b);
            for (i=n;i>=a;--i){
                for (e=1;e<=b;++e){
                    if (i-a*e>=0){
                    f[i]=f[i]+f[i-a*e];}
                }
            }
        }
        printf("%lld\n",f[n]);
    }
}