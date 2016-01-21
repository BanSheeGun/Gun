#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<set>
using namespace std;

int n;
set<int> a;
set <int>::iterator af;
int b[400000];
int ans[400000];
int i,j,k,top;

int fi(int n) {
    af = a.find(n);
    if (af == a.end()) {
        return 0;
    } else {
        return 1;
    }
}

int main()
{
    scanf("%d",&n);
    top = 0;
    ans[top] = 0;
    for (i = 1;i <= n;++i) {
        scanf("%d",&k);
        b[i] = k;
        if (fi(k)) {
            a.clear();
            ++top;
            ans[top] = i;
        } else {
            a.insert(k);
        }
    }

    ans[top] = n;
    if (top != 0) {
        printf("%d\n",top);
        for (i = 1;i <= top;++i)
            printf("%d %d\n",ans[i-1] + 1, ans[i]);
    } else {
        printf("-1\n");
    }
    return 0;
}
