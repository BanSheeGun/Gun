#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

char a[100010];
char b[100];
int f[100010];
int ans[100010];
int la, lb, i, j, top;

int check(int x) {
    int i;
    for (i = 0;i < lb;++i)
        if (a[x + i] != b[i])
            return 0;
    return 1;
}

int main()
{
    scanf("%s",a);
    scanf("%s",b);
    top = 0;
    la = strlen(a);
    lb = strlen(b);
    for (i = 0;i < la -lb + 1; ++i)
        if (check(i)) {
            ++top;
            f[top] = i;
        }
    ans[0] = 0;
    for (i = 1;i <= top; ++i) {
        j = i-1;
        while (j > 0) {
            if (f[j] + lb > f[i])
                --j;
            else
                break;
        }
        ans[i] = ans[j] + 1;
    }
    printf("%d\n",ans[top]);
    return 0;
}
