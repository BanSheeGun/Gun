#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

char a[1000003];
int nex[1000003];
int aa, bb, test, i, j, ans;

int main() {
    test = 0;
    while (scanf("%d",&aa)) {
        if (aa == 0)
            return 0;
        scanf("%s",a);
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

        printf("Test case #%d\n",++test);
        for (i = 1;i <= aa;++i)
            if (i % (i - nex[i]) == 0 && i != (i - nex[i])) {
                printf("%d %d\n",i, i / (i - nex[i]));
            }
        printf("\n");
    }
    return 0;
}
