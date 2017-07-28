#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 200010;

int isColor[N];
int c[N];
int i, n, x, y;
vector<int> a[N];
ll tc, ans;
ll sum[N];
ll size[N];

inline ll C(int n) {
    return (ll)(n - 1) * n / 2;
}

int dfs(int x, int y) {
    size[x] = 1;
    ll all = 0, part = 0;
    for (int i : a[x]) {
        if (i == y)
            continue;
        int sumback = sum[c[x]];
        dfs(i, x);
        part = sum[c[x]] - sumback;
        all += part;
        ans -= C(size[i] - part);
        size[x] += size[i];
    }
    sum[c[x]] += size[x] - all;
    return 0;
}

int main() {
    int T = 0;
    while (~scanf("%d", &n)) {
        memset(isColor, 0, sizeof(isColor));
        tc = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%d", &c[i]);
            if (!isColor[c[i]])
                tc++, isColor[c[i]] = 1;
        }

        for (i = 1; i <= n; ++i)
            a[i].clear();
        for (i = 1; i < n; ++i) {
            scanf("%d%d", &x, &y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        ans = tc * C(n);

        memset(size, 0, sizeof(size));
        memset(sum, 0, sizeof(sum));
        dfs(1, 0);
        for (i = 1; i <= n; ++i)
            if (isColor[i] && i != c[1])
                ans -= C(n - sum[i]);

        printf("Case #%d: %lld\n", ++T, ans);
    }    
    return 0;
}