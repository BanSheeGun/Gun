/**************************************************************
    Problem: 2190
    User: Gunpowder
    Language: C++
    Result: Accepted
    Time:40 ms
    Memory:1292 kb
****************************************************************/
 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
 
const int N = 40000;
int prime[40010];
int phi[40010];
int p[40010];
int n, i, j, top;
 
int main() {
    memset(p, 0, sizeof(p));
    phi[1] = 1;
    top = 0;
    for (i = 2; i <= N; ++i) {
        if (!p[i]) {
            prime[++top] = i;
            phi[i] = i - 1;
        }
        for (j = 1; j <= top; ++j) {
            if (i * prime[j] > N)
                break;
            p[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
 
    ll ans = 0;
    scanf("%d", &n);
    while (n--)
        ans += phi[n];
    printf("%lld\n", ans * 2 + 1);
    return 0;
}