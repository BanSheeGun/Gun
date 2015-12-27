#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int n,i,j,t,k;
char tmp[2048];
char a[2][2048][2048];

int main()
{
    scanf("%d",&n);
    if (n == 0) {
        printf("+\n");
    } else {
        t = 2;
        strcpy(a[1][1],"++");
        strcpy(a[1][2],"+*");
        for (i = 2;i <= n;++i) {
            for (j = 1;j <= t; ++j) {
                strcpy(tmp,a[(i+1)%2][j]);
                strcat(tmp,a[(i+1)%2][j]);
                strcpy(a[i%2][j],tmp);
            }
            for (j = 1;j <= t; ++j) {
                strcpy(tmp,a[i%2][j]);
                for (k = t;k < t*2;++k)
                    tmp[k]=(tmp[k] == '+')?'*':'+';
                strcpy(a[i%2][j+t],tmp);
            }
            t = t * 2;
        }

        for (j = 1;j <= t; ++j) {
            printf("%s\n",a[n%2][j]);
        }
    }
    return 0;
}
