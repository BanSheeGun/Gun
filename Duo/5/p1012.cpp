#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;

map<int, int > t;
int a[50010];
int b[50010];
long long x[50010];
long long y[50010];
long long xx[50010];
long long yy[50010];
long long tree[200000];
long long ans, aa, bb;
int n, i;
 
int add(int k,int x) {
    for ( ; k <= n; k += k & -k) {
        tree[k] += x;
    }
    return 0;
}
 
long long sum(int k) {
    long long ans = 0;
    for ( ; k > 0; k -= k & -k) {
        ans += tree[k];
    }
    return ans;
}

bool cmp(int a, int b) {
    return a < b;
}

int main() {
    while (~scanf("%d", &n)) {
        t.clear();
        for (i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b+1, b+1+n, cmp);
        for (i = 1; i <= n; ++i)
            t[b[i]] = i;
        for (i = 1; i <= n; ++i)
            a[i] = t[a[i]];

        x[0] = 0; aa = 0;
        memset(tree, 0, sizeof(tree));
        for (i = 1; i <= n; ++i) {
            x[i] = sum(a[i]-1);
            yy[i] = sum(a[i]) - sum(a[i]-1);
            add(a[i], 1);
            aa += x[i];
            yy[i] = i-1 - x[i] - yy[i];
        }

        y[0] = 0; bb = 0;
        memset(tree, 0, sizeof(tree));
        for (i = n; i >= 1; --i) {
            y[i] = sum(a[i]-1);
            xx[i] = sum(a[i]) - sum(a[i]-1);
            add(a[i], 1);
            bb += y[i];
            xx[i] = (n - i) - y[i] - xx[i];
        }

        ans = aa * bb;

        for (i = 1; i <= n; ++i) {
            ans -= (x[i] + xx[i]) * (y[i] + yy[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}