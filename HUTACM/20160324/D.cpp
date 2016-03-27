#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[1000003];
int nex[1000003];
int aa, bb, test, i, j, ans;

int main() {
    scanf("%d", &test);
    while (test--) {
        scanf("%s",a);
        aa = strlen(a);
        memset(nex,0,sizeof(nex));

        i = 0; j = -1;
        nex[0] = -1;
        while (i < aa) {
            if (j == -1 || a[i] == a[j]) {
                ++i;
                ++j;
                nex[i] = j;
            } else {
                j = nex[j];
            }
        }

        ans = (aa - nex[aa]);
        if (ans != aa) {
            ans = ((aa - 1) / ans + 1) * ans - aa;
        }
        printf("%d\n",ans);
    }
    return 0;
}
