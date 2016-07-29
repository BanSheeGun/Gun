#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;


struct Num {
    int x, now, left, right;
};
int tree[300000];
int n, m, i, x, y, k;
int ans;
Num a[100010];

int add(int k,int x) {
    for ( ; k <= n; k += k & -k) {
        tree[k] += x;
    }
    return 0;
}
 
int sum(int k) {
    int ans = 0;
    for ( ; k > 0; k -= k & -k) {
        ans += tree[k];
    }
    return ans;
}

bool cmp(Num a, Num b) {
    return a.x < b.x;
}

int main() {
    int ttt, tt;
    scanf("%d", &ttt);
        for (tt = 1; tt <= ttt; ++tt) {
        memset(tree,0,sizeof(tree));
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            scanf("%d", &a[i].x);
            a[i].now = i;
            a[i].left = i;
            a[i].right = i;
        }

        for (i = n; i >= 1; --i) {
            a[i].now += sum(a[i].x);
            add(a[i].x, 1);
            a[i].right = max(a[i].right, a[i].now);
            a[i].left = min(a[i].left, a[i].now);
        }
        printf("Case #%d:", tt);
        sort(a+1, a+1+n, cmp);
        for (i = 1; i <= n; ++i) {
            a[i].right = max(a[i].right, i);
            a[i].left = min(a[i].left, i);
            printf(" %d", a[i].right - a[i].left);
        }
        printf("\n");
    }
    return 0;
}