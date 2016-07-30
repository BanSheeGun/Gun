#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

long long s[100010][36];
int nxt[100010][36];
long long m[100010][36];
long long tmp, i, j, k, as, am;
int n;

int work(int n, long long k, int t) {
    if (k == 0) return 0;
    if (k % 2 == 1) {
        as = as + s[n][t];
        am = min(am, m[n][t]);
        work(nxt[n][t], k/2, t+1);
        return 0;
    }
    if (k != 0)
        work(n, k/2, t+1);
}

int main() {
    scanf("%d%I64d", &n, &k);
    for (i = 0; i < n; ++i)
        scanf("%d", &nxt[i][0]);
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &m[i][0]);
        s[i][0] = m[i][0];
    }
    for (i = 1; i <= 35; ++i) {
        for (j = 0; j < n; ++j) {
            nxt[j][i] = nxt[nxt[j][i-1]][i-1];
            m[j][i] = min(m[j][i-1], m[nxt[j][i-1]][i-1]);
            s[j][i] = s[j][i-1] + s[nxt[j][i-1]][i-1];
        }
    }

    for (i = 0; i < n; ++i) {
        as = 0; am = 100000000;
        work(i, k, 0);
        printf("%I64d %I64d\n", as, am);
    }
    return 0;
}