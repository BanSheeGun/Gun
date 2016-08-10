#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int t[100000];
int p[100000];
int i, j, k, n, pt;

int pan(int k) {
    for (int i = 1; i <= pt; ++i) {
        if (p[i] > sqrt(k))
            return 1;
        if (k % p[i] == 0)
            return 0;
    }
    return 1;
}

int main() {
    memset(t, 0, sizeof(t));
    pt = 0;
    for (i = 2; i < 100000; ++i) {
        if (t[i] == 0) {
            ++pt; p[pt] = i;
            for (j = 2 * i; j < 100000; j = j + i) {
                t[j] = 1;
            }
        }
    }

    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &k);
        if (pan(k))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}