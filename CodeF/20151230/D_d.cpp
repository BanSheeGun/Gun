#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int m = 1000000007;
int a[6000];
char aa[6000];
int f[6000][6000];
int s[6000][6000];
int n,i,j,k,ans;

bool pan(int x,int y,int n) {
    int i;
    for (i = 0;i < n;++i) {
        if (a[x+i]>a[y+i]) return 0;
        if (a[x+i]<a[y+i]) return 1;
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",aa);
    memset(f,0,sizeof(f));
    memset(s,0,sizeof(s));
    for (i = 1;i <= n;++i)
        a[i] = (int)aa[i-1] -48;

    for (i = 1;i <= n; ++i) {
        f[1][i] = 1;
        for (j = 2;j <= i;++j)
            if (a[j] != 0) {
                for (k = 1;k<=j - 1;++k) {
                    f[j][j+i-1] += f[k][j-1];
                    f[j][j+i-1] %= m;
                }
            }
        for (j = i+1;j <= n - i + 1; ++j)
            if (a[j] != 0) {
                for (k = 1;k <= i-1;++k) {
                    f[j][j+i-1] += f[j-k][j-1];
                    f[j][j+i-1] %=m;
                }
                if (pan(j - i,j,i)) {
                    f[j][j+i-1] += f[j-i][j-1];
                    f[j][j+i-1] %=m;
                }
            }
    }

    ans = 0;
    for (i = 1;i <= n; ++i)
        ans = (ans + f[n-i+1][n]) % m;
    printf("%d\n",ans);
    return 0;
}
