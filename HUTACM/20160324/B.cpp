#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[10000003];
char b[10003];
int nex[10003];
int aa, bb, test, i, j, ans;

int main() {
    scanf("%d",&test);
    while (test--) {
        scanf("%s",b);
        scanf("%s",a);
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

        ans = 0;
        i = 0; j = 0;
        while (i < aa && j< bb) {
            if (j == -1 || a[i] == b[j]) {
                ++i;
                ++j;
            } else {
                j = nex[j];
            }
            if (j >= bb) {
                ++ans;
                j = nex[j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
