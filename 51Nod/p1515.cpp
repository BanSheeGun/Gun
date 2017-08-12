#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
typedef long long ll;

const int N = 100000;
int sum[N + 10];
int f[100010];
int i, x, y, z, fx, fy, L, T, now;
int ans[100010];
set<int> s[N];
bool OK;
map<int, int> hs;
int top;

int find(int x) {
    if (f[x] != x)
        f[x] = find(f[x]);
    return f[x];
}

inline void init() {
    for (i = 1; i <= N; ++i)  {
        f[i] = i;
        sum[i] = 1;
        s[i].clear();
    }
    return;
}

inline int work() {        
    scanf("%d%d%d", &x, &y, &z);
    if (hs[x] == 0)
        hs[x] = ++top;
    if (hs[y] == 0)
        hs[y] = ++top;
    x = hs[x];
    y = hs[y];
    fx = find(x);
    fy = find(y);
    if (z == 1) {
        if (fx == fy)
            return 0;
        auto it1 = s[fx].find(fy);
        auto it2 = s[fy].find(fx);
        if (it1 != s[fx].end() && it2 != s[fy].end()) {
            OK = 0;
            return 0;
        }
        if (sum[fx] > sum[fy]) {
            for (auto it1 = s[fy].begin(); it1 != s[fy].end(); ++it1) {
                s[*it1].erase(fy);
                s[*it1].insert(fx);
                s[fx].insert(*it1);
            }
            f[fy] = fx;
            sum[fx] += sum[fy];
            s[fy].clear();
        } else {                    
            for (auto it1 = s[fx].begin(); it1 != s[fx].end(); ++it1) {
                s[*it1].erase(fx);
                s[*it1].insert(fy);
                s[fy].insert(find(*it1));
            }
            f[fx] = fy;
            sum[fy] += sum[fx];
            s[fx].clear();
        }
    } else {
        if (fx == fy) {
            OK = 0;
            return 0;
        } 
        s[fx].insert(fy);
        s[fy].insert(fx);
    }
    return 0;
}

int main() {
    scanf("%d", &L);
    hs.clear();
    top = 0;
    init();
    now = 0;
    for (i = 1; i <= L; ++i) {
        OK = 1;
        work();
        if (OK == 0)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}