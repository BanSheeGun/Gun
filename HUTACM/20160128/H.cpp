#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

bool cmp(int a,int b) {
    return a < b;
}

int a[22];
int t[1010];
int b,tt,n,m,i,ans;

int check(int pip) {
    int i,top;
    top = 0;
    for (i = pip+1;i <= n*m; ++i) {
        if (t[i] == 0) {
            t[i] = 1;
            ++top;
            break;
        }
    }
    if (top == 0) {
        b = 0;
        return 0;
    }
    for (i = 1;i <= n*m; ++i) {
        if (t[i] == 0) {
            t[i] = 1;
            ++top;
        }
        if (top == n - 1) {
            --ans;
            return 0;
        }
    }
    b = 0;
    return 0;
}

int main()
{
    tt = 0;
    scanf("%d%d",&n,&m);
    while (n != 0 && m != 0) {
        ++tt;
        memset(t,0,sizeof(t));
        printf("Case %d: ",tt);
        for (i = 0;i < m; ++i) {
            scanf("%d",&a[i]);
            t[a[i]] = 1;
        }
        sort(a,a+m,cmp);
        ans = m;
        b = 1;
        for (i = 0;i < m;++i) {
            check(a[i]);
            if (b == 0) break;
        }
        printf("%d\n",ans);
        scanf("%d%d",&n,&m);
    }
    return 0;
}
