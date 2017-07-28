#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
long long ans;
int N;
 
int b[250010];
int n, i, k;

inline bool cmp(int a, int b) {
    return a < b;
}

int tree[4000000];

int change(int now, int l, int r, int k, int x) {
    if (l == r) {
        tree[now] = x;
        return 0;
    }
    int mid = (l + r) / 2;
    if (k <= mid)
        change(now*2, l, mid, k, x);
    else
        change(now*2+1, mid+1, r, k, x);
    tree[now] = max(tree[now*2], tree[now*2+1]);
    return 0;
}

int find(int now, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr)
        return tree[now];
    int mid = (l + r) / 2;
    int ans = 0;
    if (ll <= mid)
        ans = max(ans, find(now*2, l, mid, ll, rr));
    if (rr > mid)
        ans = max(ans, find(now*2+1, mid+1, r, ll, rr));
    return ans;
}

int main() {
    while (~scanf("%d", &n)) {
        N = n * 2;
        memset(tree, 0, sizeof(tree));
        ans = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%d", &k);
            change(1, 1, N, i, k-i);
        }
        ans = 0;
        for (i = 1; i <= n; ++i)
            scanf("%d", &b[i]);
        sort(b+1, b+1+n, cmp);

        for (i = n+1; i <= N; ++i) {
            int tmp = find(1, 1, N, b[i-n], i-1);
            ans = (ans + tmp) % mod;
            change(1, 1, N, i, tmp-i);
        }
        printf("%lld\n", ans);
    }
    return 0;
}