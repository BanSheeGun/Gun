#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

int T;
long long tree[1000010];
int maxn = 1000000;

int add(int k,int x) {
    for ( ; k <= maxn; k += k & -k) {
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

long long n, k, i, su, ans;
long long a[100010];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &n, &k);
        memset(tree, 0, sizeof(tree));
        for (i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            add(a[i], 1);
        }
        su = 0;
        for (i = 1; i <= n; ++i) {
            add(a[i], -1);
            su += sum(a[i] - 1);
            if (su >= k)
                break;
        }
        if (su < k) {
            printf("E.M.T.\n");
            continue;
        }
        su += 1;
        ans = n+1;
        while (su != k) {
            --ans;
            if (a[ans] < a[i])
                --su;
        }
        printf("%lld %lld\n", i, ans);
    }
    return 0; 
}