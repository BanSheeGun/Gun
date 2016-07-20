#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

char a[100100];
char b[100100];
int n, t, s, i;

inline void pp(int i) {
    if ('a' != a[i] && 'a' != b[i])
        printf("a");
    else
        if ('b' != a[i] && 'b' != b[i])
            printf("b");
        else
            if ('c' != a[i] && 'c' != b[i])
                printf("c");
    return;
}

int main() {
    scanf("%d%d", &n, &t);
    scanf("%s", a);
    scanf("%s", b);
    s = 0;
    for (i = 0; i < n; ++i) {
        if (b[i] == a[i])
            ++s;
    }
    t = n - t;
    if (s >= t) {
        int tmp = 0;
        for (i = 0; i < n; ++i) {
            if (a[i] == b[i] && tmp < t) {
                printf("%c", a[i]);
                ++tmp;
            } else {
                pp(i);
            }
        }
        printf("\n");
        return 0;
    } else {
        if ((n - s) < 2 * (t - s)) {
            printf("-1\n");
            return 0;
        } else {
            int t1 = s;
            int t2 = s;
            for (i = 0; i < n; ++i) {
                if (a[i] == b[i]) {
                    printf("%c", a[i]);
                } else {
                    if (t1 < t) {
                        printf("%c", a[i]);
                        ++t1;
                    } else {
                        if (t2 < t) {
                            printf("%c", b[i]);
                            ++t2;
                        } else {
                            pp(i);
                        }
                    }
                }
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}
