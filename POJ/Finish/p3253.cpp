#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
long long ans;
int n,i,k,a,b;

int main()
{
    scanf("%d",&n);
    for (i = 1; i <= n; ++i) {
        scanf("%d",&k);
        q.push(k);
    }

    ans=0;
    for (i = 1; i < n; ++i) {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        ans += (long long)(a + b);
        q.push(a + b);
    }

    printf("%lld\n", ans);

    return 0;
}
