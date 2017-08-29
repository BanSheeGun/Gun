#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1000000;
int prime[N + 10];
bool p[N + 10];
const int M = 1e5 + 10;
ll ans[M];
int l[M];
int r[M];
int sum[M];
int a[M];
int i, j, top, n, m;
const int maxn = 1e5;

struct IntervalTree
{
    ll sum[maxn<<3];
    void build(){memset(sum,0,sizeof(sum));}
    void update(int o,int l,int r,int pos,int val)
    {
        if(l==r)
        {
            sum[o]+=val;
            return;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)update(o<<1,l,mid,pos,val);
        else update(o<<1|1,mid+1,r,pos,val);
        sum[o]=sum[o<<1]+sum[o<<1|1];
    }
    ll query(int o,int l,int r,int q1,int q2)
    {
        if(q1<=l&&r<=q2)return sum[o];
        int mid=(l+r)>>1;
        ll ans=0;
        if(q1<=mid)ans+=query(o<<1,l,mid,q1,q2);
        if(q2>mid)ans+=query(o<<1|1,mid+1,r,q1,q2);
        return  ans;
    }

}tree;

struct Q
{
    int l,r;
    int id;
    bool operator < (const Q & a)const
    {
        return r<a.r;
    }
}q[100100];
map<int,int> vis;

int main() {
    memset(p, 0, sizeof(p));
    top = 0;
    for (i = 2; i <= N; ++i) {
        if (!p[i])
            prime[++top] = i;
        for (j = 1; j <= top; ++j) {
            if (i * prime[j] > N)
                break;
            p[i * prime[j]] = 1;
            if (i % prime[j] == 0)                
                break;               
        }
    } 
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (i = 1; i <= m; ++i) {
        ans[i] = 1;
        scanf("%d%d", &l[i], &r[i]);
    }

    for (i = 1; i <= top; ++i) {
        memset(sum, 0, sizeof(sum));
        for (j = 1; j <= n; ++j) {
            sum[j] = sum[j-1];
            while (a[j] % prime[i] == 0) {
                ++sum[j];
                a[j] /= prime[i];
            }
        }

        for (j = 1; j <= m; ++j)
            ans[j] = ans[j] * (sum[r[j]] - sum[l[j] - 1] + 1) % mod;
    }

    tree.build();
    for (i = 1; i <= m; ++i) {
        q[i].l = l[i];
        q[i].r = r[i];
        q[i].id = i;
    }
    sort(q+1, q+1+m);
    vis.clear();
    int cur=1;
    for(int i=1;i<=m;i++) {
        for(;cur<=n&&cur<=q[i].r;cur++) {
            if(vis[a[cur]])tree.update(1,1,n,vis[a[cur]],-1);
            tree.update(1,1,n,cur,1);
            vis[a[cur]]=cur;
        }
        ans[q[i].id] *= tree.query(1,1,n,q[i].l,q[i].r);
        ans[q[i].id] %= mod;
    }

    for (i = 1; i <= m; ++i) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}