#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[1000003];
char b[1000003];
int nex[1000003];
int aa, bb, test, i, j, ans, tt, ttt;

int main() {
    scanf("%d", &tt);
    ttt = 0;
    while (tt--) {
        scanf("%s",a);
        aa = strlen(a);
        bb = aa;
        for (i = 0; i < aa; ++i) {
            b[i] = a[aa - i -1];
        }
        memset(nex,0,sizeof(nex));

        i = 0; j = -1;
        nex[0] = -1;
        while (i < bb) {
            if (j == -1 || b[i] == b[j]) {
                ++i;
                ++j;
                nex[i] = j;
            } else {
                j = nex[j];
            }
        }

        ans = 0;
        i = 0; j = 0;
        while (i < aa && j < bb) {
            if (j == -1 || a[i] == b[j]) {
                ++i;
                ++j;
            } else {
                j = nex[j];
            }
        }
        printf("Case %d: %d\n",++ttt, 2 * aa - j);
    }
    return 0;
}
