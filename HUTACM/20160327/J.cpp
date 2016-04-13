#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 400100;

struct Line {
    int x, u, d, f;
};

bool cmp(Line a, Line b) {
    return a.x < b.x;
}

bool cmp1(int a, int b) {
    return a < b;
}

int y[60010];
Line a[60010];
int tl[N], tr[N], lc[N], rc[N], ans[N], cover[N];
int top, n, i, test, xx1,xx2,yy1,yy2,maxy, now, lx, m;

inline int change(int k, int l, int r,int flag) {
    if (l==r) return 0;
    if (l <= tl[k] && tr[k] <= r) {
        if (cover[k] >=0) {
            cover[k] += flag;
            ans[k] = 0;
            if (cover[k] > 0) {
                ans[k] = (y[tr[k]] - y[tl[k]]);
            }
        } else {
            change(lc[k],l,r,flag);
            change(rc[k],l,r,flag);
            ans[k] = ans[lc[k]] + ans[rc[k]];
        }
        return 0;
    }
    int mid = (tr[k] + tl[k]) >> 1;
    if (cover[k] >= 0) {
        ++top;
        lc[k] = top;
        tl[top] = tl[k];
        tr[top] = mid;
        lc[top] = 0;
        rc[top] = 0;
        cover[top] = cover[k];
        ans[top] = (cover[top] == 0) ? 0 : (y[tr[top]] - y[tl[top]]);
        ++top;
        rc[k] = top;
        tl[top] = mid;
        tr[top] = tr[k];
        lc[top] = 0;
        rc[top] = 0;
        cover[top] = cover[k];
        ans[top] = (cover[top] == 0) ? 0 : (y[tr[top]] - y[tl[top]]);
        cover[k] = -1;
    }
    if (l < mid)
        change(lc[k],l,r,flag);
    if (r > mid)
        change(rc[k],l,r,flag);
    ans[k] = ans[lc[k]] + ans[rc[k]];
    return 0;
}

int main() {
//    freopen("/home/gunpowder/Gun/1.txt","w",stdout);
    scanf("%d", &test); int ttt = 0;
    while (test--) {
        m = -1;
        int maxy = 0;
        printf("Case %d: ",++ttt);
        int anss = 0;
        scanf("%d", &n);
        memset(y, 0, sizeof(y));
        memset(a, 0 , sizeof(a));
        for (i = 1;i <= n; ++i) {
            scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
            y[++m] = yy1;
            y[++m] = yy2;
            maxy = max(maxy, yy2);
            a[i*2-1].x = xx1;
            a[i*2-1].d = yy1;
            a[i*2-1].u = yy2;
            a[i*2-1].f = 1;
            a[i*2].x = xx2;
            a[i*2].d = yy1;
            a[i*2].u = yy2;
            a[i*2].f = -1;
        }
        sort(y,y+m+1,cmp1);
        sort(a+1,a+1+2*n,cmp);
        m=unique(y,y+m)-y;
        tl[1] = 0;
        tr[1] = m;
        top = 1;
        lc[1] = 0;
        rc[1] = 0;
        cover[1] = 0;
        ans[1] = 0;
        now = 0;
        lx = 0;
        a[n*2+1].x = -1;
        while (now < 2*n) {
            ++now;
            anss += ans[1] * (a[now].x - lx);
            --now;
            do {
                ++now;
                int l = lower_bound(y,y+m,a[now].d)-y;
                int r = lower_bound(y,y+m,a[now].u)-y;
                change(1,l,r,a[now].f);
            } while (a[now].x == a[now+1].x);
            lx = a[now].x;
        }
        printf("%d\n",anss);
    }
    return 0;
}
