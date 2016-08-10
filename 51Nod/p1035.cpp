#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int t[1010];
int p[1010];
int i, j, k, n, pt, ans, m;

inline int phi(int n) {
    int ans = n, i;
    for (i = 1; i <= pt; ++i) {
        if (p[i] > n) break;
        if (n % p[i] == 0) {
            ans = ans / p[i] * (p[i] - 1);
            while (n % p[i] == 0)
                n = n / p[i];
        }
    }

    if (n != 1)
        ans = ans / n * (n - 1);
    return ans;
}

inline int find(int n, int m) {
    int tmp = 1;
    for (int i = 1; i <= m; ++i) {
        tmp = tmp * 10 % n;
        if (m % i == 0)
            if (tmp == 1)
                return i;
    }
    return m;
}

int main() {
    memset(t, 0, sizeof(t));
    pt = 0;
    for (i = 2; i < 1000; ++i) {
        if (t[i] == 0) {
            ++pt; p[pt] = i;
            for (j = 2 * i; j < 1000; j = j + i) {
                t[j] = 1;
            }
        }
    }
    scanf("%d", &n);
    ans = 1;
    int a2 = 3;
    for (i = 3; i <= n; ++i) {
        if (i % 2 == 0 || i % 5 == 0) continue;
        m = phi(i);
        int o = find(i, m);
        if (o > ans) {
            ans = o;
            a2 = i;
        }
    }
    printf("%d\n", a2);
    return 0;
}