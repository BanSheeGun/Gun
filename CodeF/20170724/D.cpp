#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

struct E {
    int to, next;
} edge[200100];
int head[200100];
int p[200100][25];
int n, Q, i, k, ans;
int d[200100];

void dfs(int u){
    for(int i=head[u];i!= 0 ;i=edge[i].next){
        int to=edge[i].to;
        if(to==p[u][0])continue;
        d[to]=d[u]+1;
        p[to][0]=u; 
        dfs(to); 
    }
}

void init(){
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            p[i][j]=p[p[i][j-1]][j-1];
        }
    }
}

int lca(int a,int b){
    if(d[a]>d[b])swap(a,b);
    int f=d[b]-d[a];
    for(int i=0;(1<<i)<=f;i++){
        if((1<<i)&f)b=p[b][i];
    }
    if(a!=b){
        for(int i=(int)log2(n);i>=0;i--){
            if(p[a][i]!=p[b][i]){
                a=p[a][i]; b=p[b][i];
            }
        }
        a=p[a][0];
    }
    return a;
}

inline void add(int n, int to, int fa) {
    edge[n].next = head[fa];
    head[fa] = n;
    edge[n].to = to;
    return;
}

int a, b, c;

inline int dis(int a, int b) {
    int tmp = lca(a, b);
    return d[a] + d[b] - 2 * d[tmp] + 1;
}

inline bool isson(int a, int b) {
    return lca(a, b) == a;
}
inline int work(int s, int t, int f) {
    if (isson(f, s) == isson(f, t)) {
        int tmp = lca(s, t);
        int t1 = lca(s, f);
        int t2 = lca(t, f);
        if (isson(tmp, t1))
            tmp = t1;
        if (isson(tmp, t2))
            tmp = t2;
        tmp = dis(tmp, f);
        tmp = min(dis(s, f), tmp);
        tmp = min(dis(t, f), tmp);
        return tmp;
    }
    return 1;
}

int main() {
    scanf("%d%d", &n, &Q);
    memset(head, 0, sizeof(head));
    for (i = 1; i <= n-1; ++i) {
        scanf("%d", &k);
        add(i*2-1, i+1, k);
        add(i*2, k, i+1);
    }
    dfs(1);
    init();
    while (Q--) {
        scanf("%d%d%d", &a, &b, &c);
        ans = 0;
        ans = max(work(a, b, c), ans);
        ans = max(work(a, c, b), ans);
        ans = max(work(c, b, a), ans);
        printf("%d\n", ans);
    }
    return 0;
}