#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

double ans;
int k, w;
int f[2010][2010];
int p[2010];

inline int ff(int l, int w) {
    int i;
    int ans = p[l];
    ans += l;
    if (l < 3 || w == 1)
        return ans;
    int tmp = l+1;
    i = (l+1)/2;
    ans = min(ans, f[i-1][w-1]+f[l-i][w]+tmp);
    while (i <= l && f[i][w-1]+f[l-i-1][w]+tmp < ans) {
        ++i;
        ans = f[i-1][w-1]+f[l-i][w]+tmp;
    }
    while (i >= 2 && f[i-2][w-1]+f[l-i+1][w]+tmp < ans) {
        --i;
        ans = f[i-1][w-1]+f[l-i][w]+tmp;
    }
    return ans;
}

int main() {
    memset(f, 0, sizeof(f));
    memset(p, 0, sizeof(p));
    for (k = 1; k <= 2000; ++k)
        p[k] = p[k-1] + k;
    for (k = 1; k <= 2000; ++k)
        for (w = 1; w <= 2000; ++w) {
            f[k][w] = ff(k, w);
        }
    while (~scanf("%d%d", &k, &w)) {
        ans = f[k][w];
        printf("%.6lf\n", ans/(k+1));
    }
    return 0;
}