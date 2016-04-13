#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;

struct balala {
    int a, b;  
}a[500010];

bool cmp(balala a, balala b) {
    return a.a < b.a;
}

int n, i, t, ans;
int s[500010];
int f[500010];

int find(int l, int r, int k) {
    if (l == r)
        return l;
    int mid = (l + r + 1) >> 1;
    if (s[mid] < k)
        return find(mid, r, k);
    return find(l, mid-1, k);
}

int main() {
    int test = 0;
    while (~scanf("%d", &n)) {
        for (i = 1; i <= n; ++i)
            scanf("%d%d",&a[i].a, &a[i].b);
        sort(a+1, a+1+n, cmp);
        for (i = 1; i <= n; ++i)
            s[i] = n+1;
        s[0] = 0;
        memset(f, 0, sizeof(f));
        ans = 0;
        for (i = 1; i <= n; ++i) {
            t = find(0, ans, a[i].b);
            ++t;
            f[i] = t;
            s[t] = min(a[i].b, s[t]);
            ans = max(f[i], ans);
        }
        printf("Case %d:\n", ++test);
        if (ans == 1) 
            printf("My king, at most %d road can be built.\n\n", ans);
        else 
            printf("My king, at most %d roads can be built.\n\n", ans);
    }
    return 0;
}
