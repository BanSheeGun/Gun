#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

char a[100010];
char ra[100010];
char b[100010];
char rb[100010];

inline void strRev(char *s) {
    char temp, *end = s + strlen(s) - 1;
    while( end > s)
    {
        temp = *s;
        *s = *end;
        *end = temp;
        --end;
        ++s;
    }
}

inline bool cmp(char *a, char * b) {
    int la = strlen(a);
    int lb = strlen(b);
    for (int i = 0; i < la; ++i) {
        if (i == lb) return 0;
        if (a[i] < b[i]) return 1;
        if (a[i] > b[i]) return 0;
    }
    return 1;
}

int n, i;
long long f[100010];
long long t[100010];
long long c[100010];
long long ans;

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        f[i] = 1e18;
        t[i] = 1e18;
        scanf("%lld", &c[i]);
    }
    scanf("%s", b);
    strcpy(rb, b);
    strRev(rb);
    f[1] = 0; t[1] = c[1];
    for (i = 2; i <= n; ++i) {
        scanf("%s", a);
        strcpy(ra, a);
        strRev(ra);
        if (cmp(b, a))
            f[i] = min(f[i], f[i-1]);
        if (cmp(rb, a))
            f[i] = min(f[i], t[i-1]);
        if (cmp(b, ra))
            t[i] = min(t[i], f[i-1] + c[i]);
        if (cmp(rb, ra))
            t[i] = min(t[i], t[i-1] + c[i]);

        strcpy(b, a);
        strcpy(rb, ra);
    }
    ans = min(f[n], t[n]);
    if (ans == 1e18)
        printf("-1\n");
    else
        printf("%lld\n", ans);
    return 0;
}