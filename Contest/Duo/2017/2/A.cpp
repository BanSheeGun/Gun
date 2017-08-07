#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

char a[90000];
char b[90000];
int x, y, d, i, n, T;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &x, &y);
        scanf("%s", a);
        scanf("%s", b);
        d = 0;
        for (i = 0; i < n; ++i)
            if (a[i] != b[i])
                d++;
        int tmp = min(x, y);
        tmp = min(tmp, n - d);
        x -= tmp;
        y -= tmp;
        if (x + y <= d)
            printf("Not lying\n");
        else
            printf("Lying\n");
    }
    return 0;
}