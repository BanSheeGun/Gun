#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5+5;
int in[N], val[N];
vector<int>od;
int seed[N], flag, i, n, m, ans, u, v, T;
struct Seg{
    int l,r,v;
     bool operator<(const Seg &rhs)const{
        return r<rhs.r;
    }
};
struct ask{
    int l,r,id;
    bool operator<(const ask &rhs)const{
        return r<rhs.r;
    }
};
int find(int x) { 
    return seed[x] < 0? x : seed[x] = find(seed[x]); 
}
inline bool pan(int i) {
    return (seed[i] < 0 && -seed[i] > 1);
}
int main() {
    scanf("%d", &T);
    while(T--) {
        ans = 0;
        od.clear();
        scanf("%d%d", &n, &m); memset(in, 0, sizeof(in));
        memset(seed, -1, sizeof(seed));
        for(i = 1; i <= n; ++i) scanf("%d", val+i);
        for(i = 1; i <= m; ++i) {
            scanf("%d%d", &u, &v);
            in[u]++, in[v]++;
            u = find(u), v = find(v);
            if(u == v) continue;
            if(seed[u] > seed[v]) seed[v] += seed[u], seed[u] = v;
            else seed[u] += seed[v], seed[v] = u;
        }
        for(i = 1; i <= n; ++i) if(pan(i)) flag++;
        if(flag > 1){ puts("Impossible"); continue; }
        for(int i = 1; i <= n; ++i) if(in[i]%2) od.push_back(i);
        if(od.size() != 0 && od.size() != 2){ puts("Impossible"); continue; }
        if(od.size() == 0){
            ans = 0;
            for(int i = 1; i <= n; ++i) {
                if(in[i] == 0) continue;
                ans = max(ans, ans^val[i]);
            }
            printf("%d\n", ans);
        }
        else{
            for(int i = 1; i <= n; ++i) {
                if(i == od[0] || i == od[1] || in[i] == 0) continue;
                if(((in[i])/2)%2) ans ^= val[i];
            }
            ans ^= val[od[0]], ans ^= val[od[1]];
            printf("%d\n", ans);
        }
    }
    return 0;
}
