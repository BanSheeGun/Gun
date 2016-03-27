#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int a[1000002];
int b[10002];
int nex[10002];
int aa, bb, test, i, j, ans;

int main() {
    scanf("%d",&test);
    while (test--) {
        scanf("%d%d",&aa,&bb);
        for (i = 1;i <= aa; ++i) {
            scanf("%d",&a[i]);
        }
        for (i = 1;i <= bb; ++i) {
            scanf("%d",&b[i]);
        }

        memset(nex,0,sizeof(nex));

        i = 1; j = 0;
        nex[1] = 0;
        while (i <= bb) {
            if (j == 0 || b[i] == b[j]) {
                ++i;
                ++j;
                nex[i] = j;
            } else {
                j = nex[j];
            }
        }

        ans = -1;
        i = 1; j = 1;
        while (i <= aa && j<= bb) {
            if (j == 0 || a[i] == b[j]) {
                ++i;
                ++j;
            } else {
                j = nex[j];
            }
            if (j > bb) {
                ans = i  - bb;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
