#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long mod = 1e9 + 7;

int n, m, i, l, r;
int a[100020];
int b[100020];
int tree[800020];
int ll[800020];
int rl[800020];
int lx[800020];
int rx[800020];

int build(int now, int l, int r) {
    if (l == r) {
        tree[now] = 1;
        ll[now] = 1;
        rl[now] = 1;
        lx[now] = a[l];
        rx[now] = a[l];
        return 0;
    }
    int mid = (l + r) / 2;
    int ls = now*2;
    int rs = now*2 + 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    tree[now] = max(tree[ls], tree[rs]);
    if (rx[ls] == lx[rs]) {
        tree[now] = max(rl[ls] + ll[rs], tree[now]);
    }
    if (ll[ls] == mid - l + 1 && lx[ls] == lx[rs]) {
        ll[now] = ll[ls] + ll[rs];
        lx[now] = lx[ls];
    } else {
        ll[now] = ll[ls];
        lx[now] = lx[ls];
    }
    if (rl[rs] == r - mid && rx[ls] == rx[rs]) {
        rl[now] = rl[ls] + rl[rs];
        rx[now] = rx[ls];
    } else {
        rl[now] = rl[rs];
        rx[now] = rx[rs];
    }
    return 0;
}

int find(int now, int l, int r, int L, int R, int &nll, int &nlx, int &nrl, int &nrx) {
    if (L <= l && r <= R) {
        nll = ll[now];
        nrl = rl[now];
        nlx = lx[now];
        nrx = rx[now];
        return tree[now];
    }
    int mid = (l + r) / 2;
    int ls = now * 2;
    int rs = now * 2 + 1;
    if (R <= mid) {
        return find(ls, l, mid, L, R, nll, nlx, nrl, nrx);
    }
    if (L > mid) {
        return find(rs, mid+1, r, L, R, nll, nlx, nrl, nrx);
    }
    int lll, llx, lrl, lrx, ln;
    int rll, rlx, rrl, rrx, rn;
    int nn;
    ln = find(ls, l, mid, L, R, lll, llx, lrl, lrx);
    rn = find(rs, mid+1, r, L, R, rll, rlx, rrl, rrx);
    nn = max(ln, rn);
    if (lrx == rlx) {
        nn = max(nn, lrl + rll);
    }
    if (lll == mid - max(l, L) + 1 && llx == rlx) {
        nll = lll + rll;
        nlx = llx;
    } else {
        nll = lll;
        nlx = llx;
    }
    if (rrl == min(R, r) - mid && lrx == rrx) {
        nrl = lrl + rrl;
        nrx = lrx;
    } else {
        nrl = rrl;
        nrx = rrx;
    }
    return nn;
}


int main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    for (i = 1; i < n; ++i)
        a[i] = b[i] - b[i + 1];
    build(1, 1, n-1);
    while (m--) {
        scanf("%d%d", &l, &r);
        if (l == r) {
            printf("1\n");
            continue;
        }
        int t1, t2, t3, t4;
        printf("%d\n", find(1, 1, n-1, l, r-1, t1, t2, t3, t4) + 1);
    }
    return 0;
}