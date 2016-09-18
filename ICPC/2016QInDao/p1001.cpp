#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
ll num[5] = {1, 2, 3, 5, 7};
const ll maxn = 1e9 + 10;
ll a[100000];
int top;
int dfs(int x, ll now) {
    if (x == 5) return 0;
    dfs(x+1, now);
    while (now * num[x] <= maxn) {
        ++top; now *= num[x]; 
        a[top] = now;
        dfs(x+1, now);
    }
    return 0;
}

int T, n;

int find(int l, int r, int x) {
    if (l == r) return a[l];
    int mid = (l+r) / 2;
    if (a[mid] >= x)
        return find(l, mid, x);
    return find(mid+1, r, x);
}

int main() {
    top = 1; a[1] = 1;
    dfs(1, 1);
    sort(a+1, a+1+top);
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", find(1, top, n));
    }
    return 0;
}