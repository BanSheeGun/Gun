#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int T, n, i, t;
int a[100010];
int f[100010];
int b[100010];

int find(int l, int r, int x) {
    if (l == r) return l;
    int mid = (l+r+1)/2;
    if (b[mid] >= x)
        return find(mid, r, x);
    return find(l, mid-1, x);
}

inline int work() {
    memset(b, 0, sizeof(b));
    memset(f, 0, sizeof(f));
    b[0] = 1e6; int ans = 0;
    for (i = 1; i <= n; ++i) {
        f[i] = find(0, n, a[i])+1;
        b[f[i]] = max(b[f[i]], a[i]);
        ans = max(ans, f[i]);
    }
    if (ans >= (n-1))
        return 1;
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        t = work(); 
        for (i = 1; i <= n / 2; ++i) {
            int tmp = a[i];
            a[i] = a[n-i+1];
            a[n-i+1] = tmp;
        }
        if (work()) t = work();
        if (t)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}