#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[2000];
int t,ans,i,n;

int main() {
    scanf("%d",&n);
    for (i = 1;i <= n;++i) {
        scanf("%d",&a[i]);
    }

    scanf("%d",&t);
    ans = -1;
    for (i = n;i >= 1;--i) {
        if (a[i] == t) ans = i;
    }
    printf("%d\n",ans);
    return 0;
}
