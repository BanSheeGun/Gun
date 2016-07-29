#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[100010];
char b[100010];
int nex[100010];
int t[100010];
int f1[100010];
int f2[100010];
int aa, bb, test, i, j, ans, tt;

int main() {
    scanf("%d",&test); tt = 0;
    while (test--) {
        ++tt;
        scanf("%s",a);
        scanf("%s",b);
        aa = strlen(a);
        bb = strlen(b);
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
        memset(t, 0, sizeof(t));
        memset(f1, 0, sizeof(f1));
        memset(f2, 0, sizeof(f2));
        i = 0; j = 0;
        while (i < aa && j< bb) {
            if (j == -1 || a[i] == b[j]) {
                ++i;
                ++j;
            } else {
                j = nex[j];
            }
            if (j >= bb) {
                t[i] = 1;
                j = nex[j];
            }
        }

        f1[0] = 1;
        for (i = 1; i <= aa; ++i) {
            f1[i] = f1[i-1] + f2[i-1];
            f1[i] %= 1000000007;
            if (t[i] == 1) {
                f2[i] = f2[i - bb] + f1[i - bb];
                f2[i] %= 1000000007;
            } 
        }
        ans = f1[aa] + f2[aa];
        ans = ans % 1000000007;
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}
