#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int N = 100000;
const ll inf = 1e18;
struct line{ int v; ll w; };
struct point{ int v, mark; ll d;
    bool operator < (const point &p) const { if(p.d != d) return p.d<d; return p.v<v; }
};

int n,m;
ll d[N + 10][3];
int dp[N + 10][3];
bool vis[N + 10][3];
bool pan[N + 10];
ll Min;
vector<line>vet[N + 10];
 
void Dijkstra(int s,int t){
    for(int i = 1;i <= n;i++){
        d[i][1] = d[i][2] = inf;
    }
    memset(dp,0,sizeof(dp));
    memset(vis,false,sizeof(vis));
    priority_queue<point>Q;
    point p,q;
    d[s][1] = 0;
    dp[s][1] = 1;
    p.d = 0,p.mark = 1,p.v = s;
    Q.push(p);
    while(!Q.empty()){
        p = Q.top();
        Q.pop();
        if(vis[p.v][p.mark])continue;
        vis[p.v][p.mark] = true;
        for(int i = 0;i<vet[p.v].size();i++){
            int v = vet[p.v][i].v;
            int w = vet[p.v][i].w;
            if(!vis[v][1] && p.d + w<d[v][1]){
                if(w < Min) Min  =  w;
                if(d[v][1] != inf){
                    q.v = v,q.d = d[v][1],q.mark = 2;
                    d[v][2] = d[v][1];
                    dp[v][2] = dp[v][1];
                    Q.push(q);
                }
                d[v][1] = p.d + w;
                dp[v][1] = dp[p.v][p.mark];
                q.v = v,q.d = d[v][1],q.mark = 1;
                Q.push(q);
            }else if(!vis[v][1] && p.d + w == d[v][1]){
                dp[v][1] +=  dp[p.v][p.mark];
            }else if(!vis[v][2] && p.d + w<d[v][2]){
                d[v][2] = p.d + w;
                dp[v][2] = dp[p.v][p.mark];
                q.d = d[v][2],q.v = v,q.mark = 2;
                Q.push(q);
            }else if(!vis[v][2] && p.d + w == d[v][2]){
                dp[v][2] +=  dp[p.v][p.mark];
            }
        }
    }
}
 
int u,v, T;
ll w;

inline int init() {
    Min = inf;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)vet[i].clear();
    for(int i = 1;i <= m;i++){
        scanf("%d%d%lld",&u,&v,&w);
        line p;
        p.v = v,p.w = w;
        vet[u].push_back(p);
        p.v = u;
        vet[v].push_back(p);
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        init();
        Dijkstra(1,n);
        if(dp[n][1] >= 2){
            printf("%lld\n",d[n][1]);
        } else {
            if(dp[n][2] >= 1){
                printf("%lld\n",d[n][2]);
            } else {
                printf("%lld\n",d[n][1] + Min + Min);
            }
        }
    }
    return 0;
}