#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int base = 9973;

char a[100100];
int tree[400100];
int n, l, ans, x, y, i;

inline void creat(int k, int l, int r) {
    if (l == r) {
        tree[k] = a[l-1] - 28;
        return ;
    }
    int mid = (l + r) >> 1;
    int lc = k * 2;
    int rc = k * 2 + 1;
    creat(lc, l, mid);
    creat(rc, mid+1, r);
    tree[k] = tree[lc] * tree[rc] % base;
    return ;
}

inline int find(int k, int l, int r, int x, int y) {
    if (l == r)
        return tree[k];
    if (x <= l && r <= y)
        return tree[k];
    int ans = 1;
    int mid = (l + r) >> 1;
    int lc = k * 2;
    int rc = k * 2 + 1;
    if (x <= mid)
        ans = ans * find(lc, l, mid, x, y) % base;
    if (y > mid)
        ans = ans * find(rc, mid+1, r, x, y) % base;
    return ans;
}

int main() {
    while (~scanf("%d", &n)) {
        getchar();
        scanf("%s", a);
        l = strlen(a);
        memset(tree, 0, sizeof(tree));
        creat(1, 1, l);
        for (i = 1; i <= n; ++i) {
            scanf("%d%d", &x, &y);
            if (x > y) {
                printf("0\n");
                continue;
            }
            ans = find(1, 1, l, x, y);
            printf("%d\n", ans);
        }
    }
    return 0;
}
