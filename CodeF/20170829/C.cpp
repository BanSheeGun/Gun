#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
std::vector<int> v[200010];
int a[200010];
int ans[200010];
int n, i, x, y;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int dfs(int x, int fa, set<int> & t, int now) {
    set<int> tmp;
    tmp.clear();
    for (auto i : t) {
        ans[x] = max(ans[x], gcd(i, a[x]));
        tmp.insert(gcd(i, a[x]));
    }
    ans[x] = max(ans[x], now);
    tmp.insert(now);
    now = gcd(a[x], now);
    tmp.insert(now);
    for (auto i: v[x])
        if (i != fa)
            dfs(i, x, tmp, now);
    return 0;
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        v[i].clear();
    }
    memset(ans, 0, sizeof(ans));
    for (i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    set<int> t;
    t.clear();
    t.insert(0);
    dfs(1, 0, t, 0);
    for (i = 1; i < n; ++i)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}