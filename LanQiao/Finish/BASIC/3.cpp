#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int n,m,i,j;

int main() {
    scanf("%d%d",&n,&m);
    for (i = 1;i <= n;++i) {
        for (j = 1;j <= m; ++j)
            printf("%c",65+abs(i - j));
        printf("\n");
    }
    return 0;
}
