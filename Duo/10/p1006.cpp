#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;

struct Point {
    long long x, y, de;
};

struct Line {
    long long x, y1, y2;
};

inline bool cmp1(const Line a, const Line b) {
    return a.x < b.x;
}

inline bool cmp2(const Point a, const Point b) {
    return a.x < b.x;
}

inline bool cmp3(const long long a, const long long b) {
    return a < b;
}

map <long long, long long> ls;
Point b[400000];
Line a[200000];
long long q[400000];
long long x, y, xx, yy, n, nn, mm, T, i, s, num, l;
long long su;
long long tree[1000000];
long long ans;
 
int add(long long k, long long x) {
    for ( ; k <= num*2; k += k & -k) {
        tree[k] += x;
    }
    return 0;
}
 
long long sum(long long k) {
    long long ans = 0;
    for ( ; k > 0; k -= k & -k) {
        ans += tree[k];
    }
    return ans;
}

int main() {
    scanf("%lld", &T);
    while (T--) {
        ls.clear(); su = 0;
        scanf("%lld", &n); s = 0; nn = 0; mm = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%lld%lld%lld%lld", &x, &y, &xx, &yy);
            ++s; q[s] = y; ++s; q[s] = yy;
            if (x == xx) {
                if (y < yy) swap(y, yy);
                ++nn;
                a[nn].x = x; a[nn].y1 = y; a[nn].y2 = yy; 
            } else {
                if (x > xx) swap(x, xx);
                ++mm; b[mm].x = x; b[mm].y = y; b[mm].de = 1;
                ++mm; b[mm].x = xx+1; b[mm].y = y; b[mm].de = -1;
            }
        }
        sort(q+1, q+1+s, cmp3); q[0] = -1000000001; num = 0;
        for (i = 1; i <= s; ++i)
            if (q[i] != q[i-1]) { ++num; ls[q[i]] = num; }
        for (i = 1; i <= nn; ++i) {a[i].y1 = ls[a[i].y1]; a[i].y2 = ls[a[i].y2];}
        for (i = 1; i <= mm; ++i) {b[i].y = ls[b[i].y];}
        sort(a+1, a+1+nn, cmp1);sort(b+1, b+1+mm, cmp2); l = 0;
        memset(tree, 0, sizeof(tree));
        for (i = 1; i <= nn; ++i) {
            while (l < mm && b[l+1].x <= a[i].x) {
                ++l; add(b[l].y, b[l].de);
            }
            ans = sum(a[i].y1) - sum(a[i].y2-1);
            su += ans;
        }
        printf("%lld\n", su);
    }
    return 0;
}