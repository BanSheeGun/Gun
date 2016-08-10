#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct ttt {
    int x, n;
};

inline bool cmp(ttt a, ttt b) {
    return a.x < b.x;
}

ttt a[1010];
int n, i, j, flag, s;

int main() {
    int T;
    scanf("%d", &T);
    for (int TT = 1; TT <= T; ++TT) {
        printf("Case #%d: ", TT);
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            a[i].n = i;
            scanf("%d", &a[i].x);
        }
        s = 0;
        sort(a+1, a+1+n, cmp);
        flag = 1;
        for (i = 1; i <= n; ++i) {
            s += a[i].x;
            if (a[i].x >= i)
                flag = 0;
        }

        if (flag == 0)
            printf("No\n");
        else {
            printf("Yes\n");
            printf("%d\n", s);
            for (i = 1; i <= n; ++i)
                for (j = 1; j <= a[i].x; ++j)
                    printf("%d %d\n", a[i].n, a[j].n);
        }
    }
    return 0;
}