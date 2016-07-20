#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

struct DX {
    int a, b, num;
};

bool cmp(DX a, DX b) {
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}

DX a[2000];
int f[2000];
int fa[2000];
int n, i, j, ans;

void aaa(int k) {
    if (fa[k] != 0)
        aaa(fa[k]);
    printf("%d\n", a[k].num);
}

int main() {
    freopen("1.txt","r",stdin);
    n = 0;
    while (~scanf("%d", &a[++n].a)) {
        scanf("%d", &a[n].b);
        a[n].num = n;
    }
    n--;
    sort(a+1, a+1+n, cmp);

    memset(f, 0, sizeof(f));
    memset(fa, 0, sizeof(fa));

    for (i = 1; i <= n; ++i) {
        f[i] = 1;
        for (j = 1; j < n; ++j) {
            if (a[j].b > a[i].b && f[j]+1 > f[i]) {
                f[i] = f[j] + 1;
                fa[i] = j;
            }
        }
    }

    ans = 1;
    for (i = 1; i <= n; ++i) {
        if (f[i] > f[ans])
            ans = i;
    }
    printf("%d\n", f[ans]);
    aaa(ans);
    return 0;
}
