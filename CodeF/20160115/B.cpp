#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int ans,now,tt,i,n;
char k[100010];
char t[100010];

int pan() {
    int ans = 0;
    int l = strlen(k);
    int i;
    if (k[0] != '1') return -1;
    for (i = 1;i < l;++i) {
        if (k[i] == '0')
            ++ans;
        else
            return -1;
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    strcpy(t,"1");
    tt = 1;
    ans = 0;
    for (i = 1;i <= n;++i) {
        scanf("%s",k);
        if (k[0] == '0')
            tt = 0;
        else {
            now = pan();
            if (now == -1) {
                strcpy(t,k);
            } else {
                ans += now;
            }
        }
    }

    if (tt) {
        printf("%s",t);
        for (i = 1;i <= ans;++i) {
            printf("0");
        }
        printf("\n");
    } else {
        printf("0\n");
    }

    return 0;
}
