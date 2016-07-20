#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

char a[1000010];
int p, l, i, tz, tx, zws, zls, xws, xls;

int main() {
    scanf("%s", a);
    l = strlen(a);
    p = l;
    for (i = 0; i < l; ++i)
        if (a[i] == '.') {
            p = i;
            break;
        }

    tz = 0;
    for (i = 0; i < p; ++i) {
        if (a[i] != '0') {
            tz = 1;
            break;
        }
    }
    tx = 0;
    for (i = p+1; i < l; ++i) {
        if (a[i] != '0') {
            tx = 1;
            break;
        }
    }

    if (tx == 0 && tz == 0) {
        printf("0\n");
        return 0;
    }

    if (tz != 0) {
        zws = 0;
        zls = p-1;
        for (i = p-1; i >= 0; --i) {
            if (a[i] != '0') {
                zws = i;
            }
        }

        while (a[zls] == '0') {
            --zls;
        }
    }


    if (tx != 0) {
        xws = 0;
        xls = p+1;
        for (i = p+1; i < l; ++i) {
            if (a[i] != '0') {
                xws = i;
            }
        }

        while (a[xls] == '0') {
            ++xls;
        }
    }

    if (tz != 0) {
        if (tx == 0) {
            printf("%c", a[zws]);
            if (zws != zls) {
                printf(".");
                for (i = zws+1; i <= zls; ++i)
                    printf("%c", a[i]);
            }
            if (zws != p-1) {
                printf("E%d\n", p - zws - 1);
            } else
                printf("\n");
        } else {
            printf("%c", a[zws]);
            printf(".");
            for (i = zws+1; i < p; ++i)
                printf("%c", a[i]);
            for (i = p+1; i <= xws; ++i)
                printf("%c", a[i]);
            if (zws != p-1) {
                printf("E%d\n", p - zws - 1);
            } else 
                printf("\n");
        }
    } else {
        printf("%c", a[xls]);
        if (xls != xws) {
            printf(".");
            for (i = xls + 1; i <= xws; ++i)
                printf("%c", a[i]);
        }
        printf("E-%d\n", xls - p);
    }
    return 0;
}