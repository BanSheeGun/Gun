#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int p[3000100];
int n, i, j, s;

int main() {
    scanf("%d", &n);
    memset(p, 0, sizeof(p));
    p[1] = 1;
    s = 0;
    for (i = 2; i <= 3*n; ++i) {
        if (p[i] != 1) {
            ++s;
            for (j = 2 * i; j <= 3*n; j = j + i)
                p[j] = 1;
        }
        if (p[i] == 0 && p[s] == 0 && i >= n) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}