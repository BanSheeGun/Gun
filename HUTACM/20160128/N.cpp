#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[1010];
char s[1010];
int n,i,t,sum;

bool cmp(int a,int b) {
    return a < b;
}

int main()
{
    while (~scanf("%s",s)) {
    n = 0;
    sum = 0;
    t = 1;
    for (i = 0;i < strlen(s);++i) {
        if (s[i] == '\n') break;
        if (s[i] == '5') {
            t = 1;
            sum = 0;
        } else {
            if (t) ++n;
            sum = sum * 10 + (int)s[i] - 48;
            a[n] = sum;
            t = 0;
        }
    }
    sort(a+1, a+1+n, cmp);
    for (i = 1;i < n; ++i)
        printf("%d ",a[i]);
    printf("%d\n",a[n]);
}
    return 0;
}
