#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

int q[100010];
int ans[100010];
int a[100010];
int t, n, i, aa, z, tt;

inline int find(int l, int r, int x) {
    if (l ==  r)
        return l;
    int mid = (l + r + 1) / 2;
    if (q[mid] < x)
        return find(mid, r, x);
    return find(l, mid-1, x);
}

int main() {
    scanf("%d", &t); tt = 0;
    while (t--) {
        ++tt;
        z = 0;
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            q[i] = 1e9 + 1;
            scanf("%d", &a[i]);
            ans[i] = 0;
        }
        ans[0] = 0;
        q[0] = -100000000;
        for (i = 1; i <= n; ++i) {
            if (a[i] == 0) {
                ++z;
                continue;
            } else {
                ans[i] = find(0, n, a[i]-z) + 1;
                q[ans[i]] = min(q[ans[i]], a[i]-z);
            }
        }
        aa = 0;
        for (i = 1; i <= n; ++i)
            aa = max(aa, ans[i]); 
        printf("Case #%d: %d\n", tt, aa + z);
    }
    return 0;
}