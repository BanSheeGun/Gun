#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

char a[9];
char b[9];
int n, m, x, y;
bool c[1000];
int ad[1000];

int main() {
    n = 0; m = 0;
    strcpy(b, "END");
    memset(c, 0, sizeof(c));
    while (1) {
        scanf("%s", a);
        if (!strcmp(a, b)) {
            break;
        }
        ++n;
        sscanf(a, "%x", &x);
        y = (x / 16) % 64;
        if (!c[y]) {
            c[y] = 1;
            ad[y] = (x/16)*16;
            puts("Miss");
        } else {
            if (ad[y] == (x/16)*16) {
                ++m;
                puts("Hit");
            } else {
                ad[y] = (x/16)*16;
                puts("Miss");
            }
        }
    }
    printf("Hit ratio = %.2lf%%\n", (double)100*m/n);
    return 0;
}