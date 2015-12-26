#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[100][100];
int n,i,j;
int main() {
    memset(a,0,sizeof(a));
    a[0][1] = 1;
    printf("1\n");
    scanf("%d",&n);
    for (i = 1;i < n;++i) {
        for (j = 1;j <= i;++j) {
            a[i][j] = a[i-1][j] + a[i-1][j-1];
            printf("%d ",a[i][j]);
        }
        a[i][i+1] = a[i-1][i+1] + a[i-1][i];
        printf("%d\n",a[i][i+1]);
    }
    return 0;
}
