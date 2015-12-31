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
    if (x<=0) return 0;
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
    a[0] = 0;
    for (i = 1;i <= n;++i)
        a[i] = (int)aa[i-1] -48;

    for (i = 1;i <= n; ++i) {
        for (j = 1;j <i;++j) 
            if (a[i-j+1] != 0) {
                if (i-j <= j-1) f[i][j] = s[i-j][i-j];
                    else f[i][j] = s[i-j][j-1];
                if (pan(i-j-j+1,i-j+1,j))
                    f[i][j] += f[i-j][j];
                f[i][j] %= m;
            }
        f[i][i] = 1;
        for (j = 1;j <=i;++j) {
            s[i][j] = (s[i][j-1] + f[i][j]) % m;
        }
    }
    printf("%d\n",s[n][n]);
    return 0;
}
