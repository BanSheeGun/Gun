#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
struct Treap  
{  
    ll size;  
    ll key,fix;  
    Treap *ch[2];  
    Treap(ll key)  
    {  
        size=1;  
        fix=rand();  
        this->key=key;  
        ch[0]=ch[1]=NULL;  
    }  
    int compare(ll x) const  
    {  
        if(x==key) return -1;  
        return x<key? 0:1;  
    }  
    void Maintain()  
    {  
        size=1;  
        if(ch[0]!=NULL) size+=ch[0]->size;  
        if(ch[1]!=NULL) size+=ch[1]->size;  
    }  
};  
  
inline void Rotate(Treap* &t,ll d)  
{  
    Treap *k=t->ch[d^1];  
    t->ch[d^1]=k->ch[d];  
    k->ch[d]=t;  
    t->Maintain();
    k->Maintain();  
    t=k;  
}  
  
inline void Insert(Treap* &t,ll x)  
{  
    if(t==NULL) t=new Treap(x);  
    else  
    {  
        int d=x < t->key ? 0:1;  
        Insert(t->ch[d],x);  
        if(t->ch[d]->fix > t->fix)  
            Rotate(t,d^1);  
    }  
    t->Maintain();  
}  
  
inline void Delete(Treap* &t,ll x)  
{  
    int d=t->compare(x);  
    if(d==-1)  
    {  
        Treap *tmp=t;  
        if(t->ch[0]==NULL)  
        {  
            t=t->ch[1];  
            delete tmp;  
            tmp=NULL;  
        }  
        else if(t->ch[1]==NULL)  
        {  
            t=t->ch[0];  
            delete tmp;  
            tmp=NULL;  
        }  
        else  
        {  
            int k=t->ch[0]->fix > t->ch[1]->fix ? 1:0;  
            Rotate(t,k);  
            Delete(t->ch[k],x);  
        }  
    }  
    else Delete(t->ch[d],x);  
    if(t!=NULL) t->Maintain();  
} 
  
inline int Rank(Treap *t,ll x)  
{  
    ll r;  
    if(t->ch[0]==NULL) r=0;  
    else  r=t->ch[0]->size;  
    if(x==t->key) return r+1;  
    if(x<t->key)  
        return Rank(t->ch[0],x);  
    return r+1+Rank(t->ch[1],x);  
}  
  
inline void DeleteTreap(Treap* &t)  
{  
    if(t==NULL) return;  
    if(t->ch[0]!=NULL) DeleteTreap(t->ch[0]);  
    if(t->ch[1]!=NULL) DeleteTreap(t->ch[1]);  
    delete t;  
    t=NULL;  
} 

const int N = 100010;
Treap *root;
int head[N];
int nxt[N];
int e[N];
int f[N];
ll ans, k, a[N];
int T, n, i, x, y, now;
multiset<ll> q;

inline int dfs(ll x) {
    multiset<ll>::iterator it = q.upper_bound(k / a[x]);
    if (it != q.begin()) {
        --it;
        ans += Rank(root, *it);
    }
    Insert(root, a[x]);q.insert(a[x]);
    for (int k = head[x]; k!=0; k = nxt[k]) {
        y = e[k];
        dfs(y);
    }
    Delete(root, a[x]);q.erase(a[x]);
    return 0;
}

int main() {  
    scanf("%d", &T);
    while (T--) {
        root = NULL;
        q.clear();
        scanf("%d%lld", &n, &k);
        for (i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        memset(head, 0, sizeof(head));
        memset(f, 0, sizeof(f));
        for (i = 1; i < n; ++i) {
            scanf("%d%d", &x, &y);
            f[y] = 1;
            e[i] = y;
            nxt[i] = head[x];
            head[x] = i;
        }
        now = 0;
        for (i = 1; i <= n; ++i)
            if (f[i] == 0) {
                now = i;
                break;
            }
        ans = 0;
        dfs(now);
        printf("%lld\n", ans);
        DeleteTreap(root);
    }
    return 0;
}  