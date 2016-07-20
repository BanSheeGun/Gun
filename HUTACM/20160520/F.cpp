#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int mod, b, i, j, ans, n, m, k;

struct Ma {
    int a[510][510];

    inline Ma operator * (const Ma &B) const {
        Ma C;
        memset(C.a, 0, sizeof(C.a));
        for (int i = 0; i <= b; ++i)
            for (int j = 0; j <= b; ++j)
                for (int k = 0; k <= b; ++k)
                    C.a[i][j] = (C.a[i][j] + a[i][k] * B.a[k][j]) % mod;
        return C;
    }

    inline void Print() {
        for (int i = 0; i <= b; ++i) {
            for (int j = 0; j <= b; ++j)
                printf("%d ", a[i][j]);
            printf("\n");
        }
    }
};

Ma t, a;

inline Ma f(int n) {
    if (n == 1)
        return a;
    t = f(n / 2);
    t = t * t;
    if (n % 2 == 1)
        t = t * a;
    return t;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &b, &mod);
    memset(a.a, 0, sizeof(a.a));
    for (i = 1; i <= n; ++i) {
        scanf("%d", &k);
        for (j = 0; j + k <= b; ++j)
            a.a[j][j+k]++;
    }
    a.Print();
    t = a*a;
    t.Print();
    t = f(m);
    t.Print();
    ans = 0;
    for (i = 0; i <= b; ++i)
        ans = (t.a[0][i] + ans) % mod;
    printf("%d\n", ans);
    return 0;
}
