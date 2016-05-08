#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct Point {
    int lt, rt;
    int d;
} t[1200000];

char a[300000];
int n, m, i, k;
char b[10];

inline int update1(int now, int l, int r) {
    int lc = now * 2;
    int rc = now * 2+1;
    t[now].lt = t[lc].lt;
    t[now].rt = t[rc].rt;
    t[now].d = t[lc].d + t[rc].d;
    if (t[lc].rt == 1 && t[rc].lt == 1)
        ++t[now].d;
}

inline int update2(int now, int l, int r) {
    if (a[l] == '.') {
        t[now].lt = 1; t[now].rt = 1; t[now].d = 0;
    } else {
        t[now].lt = 0; t[now].rt = 0; t[now].d = 0;
    }
}

inline int creat(int now, int l, int r) {
    if (l == r) {
        update2(now,l,r);
        return 0;
    }

    int mid = (l + r) >> 1;
    int lc = now * 2;
    int rc = now * 2+1;
    creat(lc, l,     mid);
    creat(rc, mid+1, r  );
    update1(now,l,r);
    return 0;
}

inline int change(int now, int l, int r, int goal) {
    if (l == r) {
        a[l] = b[0];
        update2(now,l,r);
        return 0;
    }

    int mid = (l + r) >> 1;
    int lc = now * 2;
    int rc = now * 2+1;
    if (goal <= mid)
        change(lc, l, mid, goal);
    else
        change(rc, mid+1, r, goal);
    update1(now,l,r);
    return 0;
}

int main() {
    scanf("%d%d",&n, &m);
    scanf("%s", a);
    for (i = n; i > 0; --i)
        a[i] = a[i-1];

    creat(1, 1, n);

    for (i = 1;i <= m; ++i) {
        scanf("%d", &k);
        scanf("%s", b);
        change(1, 1, n ,k);
        printf("%d\n",t[1].d);
    }
    return 0;
}
