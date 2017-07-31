#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

int a[10000];
char x, y;
int n;

int main() {
    a['^'] = 0;
    a['>'] = 1;
    a['v'] = 2;
    a['<'] = 3;
    x = getchar();
    y = getchar();
    y = getchar();
    scanf("%d", &n);
    n %= 4;
    if (n % 2 == 0 || (a[x] - a[y] + 4) % 4 % 2 == 0) {
        puts("undefined");
    } else {
        if ((a[y] - a[x] + 4) % 4 == n)
            puts("cw");
        else
            puts("ccw");
    }
    return 0;
}