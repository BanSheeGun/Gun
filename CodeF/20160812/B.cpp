#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a < b;
}

int a[100010];
int n, i, k, m;

inline int find1(int l, int r, int k) {
    if (l == r) return l;
    int mid = (l+r+1) >> 1;
    if (a[mid] <= k)
        return find1(mid, r, k);
    return find1(l, mid-1, k);
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++ i) {
        scanf("%d", &a[i]);
    }
    a[0] = 0;
    sort(a+1, a+1+n, cmp);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &k);
        printf("%d\n", find1(0, n, k));
    }
    return 0;
}