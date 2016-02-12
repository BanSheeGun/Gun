#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

long long tree[300000];
int n, m, i, x, y, k;
long long ans;

int add(int k,int x) {
    for ( ; k <= n; k += k & -k) {
        tree[k] += x;
    }
    return 0;
}

long long sum(int k) {
    long long ans = 0;
    for ( ; k > 0; k -= k & -k) {
        ans += tree[k];
    }
    return ans;
}

int main() {
    scanf("%d",&n);
    memset(tree,0,sizeof(tree));
    for (i = 1;i <= n;++i) {
        scanf("%d",&k);
        add(i, k);
    }
    scanf("%d",&m);
    while (m--) {
        scanf("%d%d%d",&k,&x,&y);
        if (k == 1) {
            add(x, y);
        } else {
            ans = 0;
            ans = sum(y);
            ans -= sum(x-1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
