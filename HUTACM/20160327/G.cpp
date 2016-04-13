#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 500000;
int l[N], r[N];
int sum[N], tag[N];
int x,y,z,n,m,test,tte;

inline void PushDown(int n) {
    if (tag[n] == 0) return;
    tag[2 * n] = tag[n];
    tag[2 * n + 1] = tag[n];
    tag[n] = 0;
    return ;
}

inline void UpDate(int n) {
    sum[n] = 0;
    int t = 2 * n;
    sum[n] += (tag[t] == 0) ? sum[t] : tag[t] * (r[t] - l[t] + 1);
    t = 2 * n + 1;
    sum[n] += (tag[t] == 0) ? sum[t] : tag[t] * (r[t] - l[t] + 1);
    return ;
}

void build(int n, int ll, int rr) {
    l[n] = ll;
    r[n] = rr;
    if (ll == rr) {
        sum[n] = 1;
        return ;
    }
    build(2 * n, ll, (ll+rr)>>1);
    build(2 * n + 1, (ll+rr)/2 + 1, rr);
    UpDate(n);
    return ;
}

void change(int n, int ll,int rr, int a) {
    if (l[n] == r[n]) {
        sum[n] = a;
        tag[n] = 0;
        return;
    }
    int mid = (l[n] + r[n]) >> 1;
    PushDown(n);
    if (ll <= l[n] && r[n] <= rr) {
        tag[n] = a;
        PushDown(n);
    } else {
        if (ll <= mid) {
            change(2*n, ll, rr, a);
        }
        if (rr > mid) {
            change(2*n+1, ll, rr, a);
        }
    }
    UpDate(n);
    return;
}

int main() {
    scanf("%d", &test);
    tte = 0;
    while (test--) {
        memset(sum, 0, sizeof(sum));
        memset(tag, 0, sizeof(tag));
        scanf("%d%d",&n,&m);
        build(1,1,n);
        while (m--) {
            scanf("%d%d%d",&x,&y,&z);
            change(1, x, y, z);
        }
        printf("Case %d: The total value of the hook is %d.\n",++tte,sum[1]);
    }
    return 0;
}
