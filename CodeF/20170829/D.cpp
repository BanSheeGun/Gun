#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int tree[3000000];
int er[30];
int n, m, k, i;

inline void work(int now, int k, int step) {
    if (step == -1) {
        tree[now] = 1;
        return;
    }
    if (k >= er[step])
        work(now*2+1, k-er[step], step-1);
    else
        work(now*2, k, step-1);
    tree[now] = tree[now*2] + tree[now*2+1];
    return;
}

inline void fuck(int now, int k, int ans, int step) {
    if (step == -1) {
        printf("%d\n", ans);
        return;
    }
    int tmp = (k & er[step]) != 0;
    if (tree[now*2+tmp] < er[step])
        fuck(now*2+tmp, k, ans, step-1);
    else
        fuck(now*2+1-tmp, k, ans+er[step], step-1);
    return;
}

int main() {
    scanf("%d%d", &n, &m);
    er[0] = 1;
    memset(tree, 0, sizeof(tree));
    for (i = 1; i <= 19; ++i)
        er[i] = er[i-1] * 2;
    while (n--) {
        scanf("%d", &k);
        work(1, k, 18);
    }
    int tmp = 0;
    k = 0;
    while (m--) {
        scanf("%d", &tmp);
        k = k ^ tmp;
        fuck(1, k, 0, 18);
    }
    return 0;
}