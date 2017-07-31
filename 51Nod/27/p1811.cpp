#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<int> a[100010];
int ma[100010];
int mi[100910];
int n, i, x, y;
ll ans;

int dfs(int x, int fa) {
    ma[x] = x;
    mi[x] = x;
    for (int y : a[x]) {
        if (y == fa)
            continue;
        dfs(y, x);
        ma[x] = max(ma[x], ma[y]);
        mi[x] = min(mi[x], mi[y]);
    }
    return 0;
}

int dfs(int x, int fa, int mma, int mmi) {
    int cma = 0, cax = 0 , ax = x;
    int cmi = n+1, cix = 0, ix = x;
    for (int y : a[x]) {
        if (y == fa)
            continue;
        if (ma[y] > mma) {
            cma = mma;
            cax = ax;
            mma = ma[y];
            ax = y;
        } else {
            if (ma[y] > cma) {
                cma = ma[y];
                cax = y;
            }
        }
        if (mi[y] < mmi) {
            cmi = mmi;
            cix = ix;
            mmi = mi[y];
            ix = y;
        } else {
            if (mi[y] < cmi) {
                cmi = mi[y];
                cix = y;
            }
        }
    }
    for (int y : a[x]) {
        if (x == y || y == fa)
            continue;
        int nma = mma, nax = ax;
        int nmi = mmi, nix = ix;
        if (y == ax) {
            nma = cma;
            nax= cax;
        }
        if (y == ix) {
            nmi = cmi;
            nix = cix;
        }
        ans += (ll)(nma - nmi + 1) * (ma[y] - mi[y] + 1);
        nma = max(nma, y);
        nmi = min(nmi, y);
        dfs(y, x, nma, nmi);
    }
    return 0;
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        a[i].clear();
    for (i = 1; i < n; ++i) {
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 0);
    ans = 0;
    dfs(1, 0, 1, 1);
    printf("%lld\n", ans);
    return 0;
}