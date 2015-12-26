#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int n,ma,mi,s,i,t;

int main() {
    scanf("%d%d",&n,&ma);
    s = ma;
    mi = ma;
    for (i = 2;i <= n;++i) {
        scanf("%d",&t);
        ma = max(ma,t);
        mi = min(mi,t);
        s += t;
    }
    printf("%d\n%d\n%d\n",ma,mi,s);
    return 0;
}
