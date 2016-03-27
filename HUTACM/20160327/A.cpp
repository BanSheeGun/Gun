#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int a[50010];
int n, i, l, r, ans, test, tt = 0;
char op[10];

inline int lowbit(int n) {
    return n & (-n);
}

int update(int k, int data) {
    for ( ;k <= n; k += lowbit(k))
        a[k] += data;
    return 0;
}

int find(int k) {
    int sum = 0;
    for (; k > 0; k -= lowbit(k))
        sum += a[k];
    return sum;
}

int main() {
    scanf("%d",&test);
    while (test--) {
        memset(a, 0, sizeof(a));
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            scanf("%d",&l);
            update(i, l);
        }

        printf("Case %d:\n", ++tt);
        while (scanf("%s", op), op[0] != 'E') {
            scanf("%d%d", &l, &r);
            if (op[0] == 'Q') {
                ans = find(r) - find(l-1);
                printf("%d\n",ans);
            } else {
                if (op[0] == 'S') r = -r;
                update(l, r);
            }
        }
    }
    return 0;
}
