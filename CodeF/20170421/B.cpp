#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

char a[60][60];
int b[60];
int l, i, n, t, ans;

int f(int x) {
    for (int i = 0; i < l; ++i) {
        int t = 1;
        for (int j = 0; j < l; ++j)
            if (a[1][j] != a[x][(j + i) % l])
                t = 0;
        if (t)
            return i;
    }
    return -1;
}

int find() {
    for (int i = 1; i <= l; ++i) {
        if (l % i != 0)
            continue;
        int t = 1;
        for (int j = 0; j < l; ++j)
            if (a[1][j] != a[1][j % i])
                t = 0;
        if (t)
            return i;
    }
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%s", a[i]);
    memset(b, 0, sizeof(b));
    l = strlen(a[1]);
    for (i = 2; i <= n; ++i) {
        b[i] = f(i);
        if (b[i] == -1) {
            printf("-1\n");
            return 0;
        }
    }
    l = find();
    b[1] = 0;
    ans = 0;
    for (i = 1; i <= n; ++i)
        ans += b[i];
    for (i = 0; i < l; ++i) {
        t = 0;
        for (int j = 1; j <= n; ++j)
            t += ((b[j] + i) % l);
        ans = min(ans, t);
    }
    printf("%d\n", ans);
    return 0; 
}