#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int t[40010];
int p[40100];
int i, j, k, n, pt, m, s;
long long ans;

inline long long phi(int n) {
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

inline long long f(int n, int k) {
    long long tmp = phi(n / k);
    tmp = tmp * k;
    return tmp;
}

int main() {
    memset(t, 0, sizeof(t));
    pt = 0;
    for (i = 2; i < 40000; ++i) {
        if (t[i] == 0) {
            ++pt; p[pt] = i;
            for (j = 2 * i; j < 40000; j = j + i) {
                t[j] = 1;
            }
        }
    }
    scanf("%d", &n);
    ans = 0;
    int s = sqrt(n);
    for (i = 1; i <= s; ++i) 
        if (n % i == 0) { 
            ans += f(n, i);
            if (i * i != n)
                ans += f(n, n / i);
        }
    printf("%lld\n", ans);
    return 0;
}