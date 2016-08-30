#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int n, i, ans;
char a[1010][10];

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%s", a[i]);
    }

    ans = 0;
    for (i = 1; i <= n; ++i) {
        if (ans == 0 && a[i][0] == 'O' && a[i][1] == 'O') {
            a[i][0] = '+';
            a[i][1] = '+';
            ans = 1;
        }
        if (ans == 0 && a[i][3] == 'O' && a[i][4] == 'O') {
            a[i][3] = '+';
            a[i][4] = '+';
            ans = 1;
        }
    }
    if (ans) {
        printf("YES\n");
        for (i = 1; i <= n; ++i)
            printf("%s\n", a[i]);
    } else {
        printf("NO\n");
    }
    return 0;
}