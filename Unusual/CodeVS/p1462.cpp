#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int isp[70000];
int pri[70000];
const int N = 69900;

int i, j, n, top, a, b;

int main() {
    top = 0;
    memset(isp, 0, sizeof(isp));
    isp[1] = 0;
    for (i = 2; i <= N; ++i) {
        if (!isp[i])
            pri[++top] = i;
        for (j = 1; j <= top; ++j) {
            if (i * pri[j] > N)
                break;
            isp[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
    scanf("%d%d", &a, &b);
    long long ans = 0;
    if (a > b)
        swap(a, b);
    for (i = 1; i <= top; ++i)
        if (pri[i] > a && pri[i] < b)
            ans += (long long)pri[i];
    printf("%lld\n", ans);
    return 0;
}