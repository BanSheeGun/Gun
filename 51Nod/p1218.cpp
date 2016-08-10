#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[50010];
int lis[50010], lib[50010];
int f[50010];
int t[50010];
int n, i, ans;

int find1(int l, int r, int k) {
    if (l == r)
        return l;
    int mid = (l+r+1) >> 1;
    if (k > f[mid])
        return find1(mid, r, k);
    return find1(l, mid-1, k);
}

int find2(int l, int r, int k) {
    if (l == r)
        return l;
    int mid = (l+r+1) >> 1;
    if (k < f[mid])
        return find2(mid, r, k);
    return find2(l, mid-1, k);
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (i = 1; i <= n; ++i)
        f[i] = 1e9 + 10;
    f[0] = -1;
    for (i = 1; i <= n; ++i) {
        lis[i] = find1(0, n, a[i]) + 1;
        f[lis[i]] = min(f[lis[i]], a[i]);
    }
    for (i = 1; i <= n; ++i)
        f[i] = -1;
    f[0] = 1e9 + 10;
    for (i = n; i >= 1; --i) {
        lib[i] = find2(0, n, a[i]) + 1;
        f[lib[i]] = max(f[lib[i]], a[i]);
    }
    ans = 0;
    for (i = 1; i <= n; ++i)
        ans = max(lis[i], ans);
    for (i = 1; i <= n; ++i)
        f[i] = -1;
    memset(t, 0, sizeof(t));
    for (i = 1; i <= n; ++i)
        if (lis[i] + lib[i] - 1 == ans) {
            if (f[lis[i]] == -1) {
                f[lis[i]] = i;
                t[i] = 2;
            } else {
                t[i] = 1;
                t[f[lis[i]]] = 1;
            }
        } else {
            t[i] = 0;
        }
    ans = 0;
    printf("A");
    for (i = 1; i <= n; ++i)
        if (t[i] == 1)
            if (ans == 0) {
                printf(":%d", i);
                ans = 1;
            } else {
                printf(" %d", i);
            }
    if (ans == 0)
        printf(":\n");
    else
        printf("\n");
    ans = 0;
    printf("B");
    for (i = 1; i <= n; ++i)
        if (t[i] == 2)
            if (ans == 0) {
                printf(":%d", i);
                ans = 1;
            } else {
                printf(" %d", i);
            }
    if (ans == 0)
        printf(":\n");
    else
        printf("\n");
    return 0;
}