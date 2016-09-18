#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=100005;
int n,m,dp[N][20];
struct Seg{
    int l,r,v;
     bool operator<(const Seg &rhs)const{
        return r<rhs.r;
    }
}seg[35*N];
struct ask{
    int l,r,id;
    bool operator<(const ask &rhs)const{
        return r<rhs.r;
    }
}p[N*10];
int hs[35*N],tot,mat[35*N];
int ans[N*10];
int c[N];
int ex(int n) {
    int t;
    if (n == 1) return 1;
    t = ex(n/2);
    t =t *t;
    return t;
}
void add(int x,int t){
    for(int i=x;i<=n;i+=i&(-i))
        c[i]+=t; 
}
int get(int x){
    int ans=0;
    if(x==0)return 0;
    for(int i=x;i>0;i-=i&(-i))
        ans+=c[i];
    return ans;
}
int find(int pos,int v){
    int l=1,r=pos;
    while(l<r){
        int mid=(l+r)>>1;
        int len=pos-mid+1;
        int now=pos,cur=-1;
        for(int i=17;i>=0;--i){
            if(len&(1<<i)){
                if(cur==-1)cur=dp[now][i];
                else cur=__gcd(cur,dp[now][i]);
                now-=(1<<i);
            }
        }
        if(cur<v)l=mid+1;
        else r=mid;
    }
    return (l+r)>>1;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;++i)
            scanf("%d",&dp[i][0]);
        for(int i=1;i<=m;++i)
            scanf("%d%d",&p[i].l,&p[i].r),p[i].id=i;
        for(int k=1;(1<<k)<=n;++k)
        for(int i=n;i>1;--i){
            int j=i-(1<<k)+1;
            if(j<1)break;
            j=i-(1<<(k-1));
            dp[i][k]=__gcd(dp[i][k-1],dp[j][k-1]);         
        }
        int cnt=0;tot=0;
        for(int i=1;i<=n;++i){
            int la=-1;
            for(int j=i;j>0;--j){
                int tmp=dp[j][0];
                if(la!=-1)tmp=__gcd(tmp,la);
                la=tmp;
                ++cnt;
                seg[cnt].l=j,seg[cnt].r=i,seg[cnt].v=la;
                hs[la]=cnt;
                j=find(i,la);
            }
        }
        sort(p+1,p+1+m);
        sort(seg+1,seg+1+cnt);
        memset(mat,0,sizeof(mat));
        memset(c,0,sizeof(c));
        int now=1;
        for(int i=1;i<=m;++i){
            for(;now<=cnt&&seg[now].r<=p[i].r;++now){
                int pos=hs[seg[now].v];
                if(seg[now].l>mat[pos]){
                    if(mat[pos])add(mat[pos],-1);
                    add(seg[now].l,1);
                    mat[pos]=seg[now].l;
                }
            }
            ans[p[i].id]=get(p[i].r)-get(p[i].l-1);
        }
        for(int i=1;i<=m;++i)
            printf("%d\n",ans[i]);
    }
    return 0;
}