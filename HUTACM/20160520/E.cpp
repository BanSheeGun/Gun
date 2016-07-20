#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int a[4000];
int n ,i, la, k, tt, t;

int main() {
    while(~scanf("%d", &n)) {
        memset(a, 0, sizeof(a));
        t = 0;
        scanf("%d", &la);
        for (i = 1; i < n; ++i) {
            scanf("%d", &k);
            tt = abs(k - la);
            if (a[tt] == 0 && tt < n && tt > 0) {
                a[tt] = 1;
            } else {
                t = 1;
            }
            la = k;
        }

        if (t == 1)
            printf("Not jolly\n");
        else
            printf("Jolly\n");
    }
    return 0;
}
