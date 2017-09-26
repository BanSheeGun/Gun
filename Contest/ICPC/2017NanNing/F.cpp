#include <cstdio>  
#include <algorithm>  
#include <cstring>
typedef long long ll;
using namespace std;  
  
struct node {  
    ll x1,x2,h;  
    int f;  
};  
node a[18005];  
  
int n,m,k=0;  
int mark[18005],lt[18005],rt[18005];  
ll lisan[18005],s[18005];  
  
bool cmp(const node & a, const node & b) {  
    return a.h<b.h;  
}  
  
void build(int l,int r,int k) {  
    mark[k]=0; s[k]=0;  
    lt[k]=l; rt[k]=r;  
    if (r-l==1)
        return;  
    int mid=(l+r)>>1;  
    build(l,mid,2*k);  
    build(mid,r,2*k+1);  
}  
  
int update(int k) {  
    if (mark[k]) 
        s[k]=lisan[rt[k]]-lisan[lt[k]];  
    else 
        if (rt[k]==lt[k]) 
            s[k]=0;  
        else
            s[k]=s[2*k]+s[2*k+1];  
}  
  
int fuck(int l,int r,int k,int f) {  
    if ((l<=lt[k])&&(rt[k]<=r)) {  
        mark[k]+=f;  
        update(k);  
        return 0;  
    }  
    int mid=(lt[k]+rt[k])>>1;  
    if (l>=mid)
        fuck(l,r,2*k+1,f);  
    else 
        if(r<=mid)
            fuck(l,r,2*k,f);  
        else {  
            fuck(l,mid,2*k,f);  
            fuck(mid,r,2*k+1,f);  
        }  
    update(k);  
}  

ll ans, i, l, r;

int main() {  
    while (~scanf("%d", &n)) {  
        memset(s, 0, sizeof(s));
        memset(lisan, 0, sizeof(lisan));
        if (n == 0) {
            printf("*\n");
            break;
        }
        ans = 0;
        m=0;  
        for (int i=0;i<n;i++) {  
            ll x1,y1,x2,y2;  
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);  
            a[m].x1=x1; a[m].x2=x2; a[m].h=y1;  
            a[m].f=1; lisan[m]=x1; m++;  
            a[m].x1=x1; a[m].x2=x2; a[m].h=y2;  
            a[m].f=-1; lisan[m]=x2; m++;  
        }  
        sort(lisan,lisan+m);  
        sort(a,a+m,cmp);  
        m=unique(lisan,lisan+m)-lisan;  
        build(0,m-1,1);  
        for (i = 0;i < 2*n-1; i++){  
            l=lower_bound(lisan, lisan + m, a[i].x1) - lisan;  
            r=lower_bound(lisan, lisan + m, a[i].x2) - lisan;  
            fuck(l,r,1,a[i].f);  
            ans += s[1] * (a[i+1].h - a[i].h);  
        }  
        printf("%lld\n", ans);
    }  
    return 0;  
}  