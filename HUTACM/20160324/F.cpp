#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[1000003];
int nex[1000003];
int aa, bb, test, i, j, ans;

int main() {
    while (scanf("%s",a)) {
        if (a[0] == '.') return 0;
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
        ans = (aa % ans == 0) ? aa / ans : 1;
        printf("%d\n",ans);
    }
    return 0;
}
