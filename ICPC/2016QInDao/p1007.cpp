#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
typedef long long ll;
ll TT, T, n, i, tmp, su, ans, m, p;
ll a[100010];

inline bool check(int l) {
    priority_queue<int, vector<int>, greater<int> > q;
    su = 0;
    p = 1; int ze = ((l-1) - (n-1) % (l-1)) % (l-1);
    while ((n-p+1+q.size()) != 1) {
        tmp = 0;
        for (i = 1; i <= l; ++i) {
            if (p > n && q.empty()) break;
            ll z;
            if (ze > 0) z = 0; else    
            if (p > n) {
                z = q.top();
                q.pop();
            } else {
                if (q.empty()) {
                    z = a[p];
                    ++p;
                } else {
                    if (q.top() < a[p]) {
                        z = q.top();
                        q.pop();
                    } else {
                        z = a[p];
                        ++p;
                    }
                }
            }
            tmp += z;
            su += z;
            if (su > T) return 0;
        }
        q.push(tmp);
    }
    if (su <= T) return 1;
    return 0;
}

int find(int l, int r) {
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (check(mid))
        return find(l, mid);
    return find(mid+1, r);
}
int main() {
    int TT;
    scanf("%d", &TT);
    while (TT--) {
        scanf("%lld%lld", &n, &T);
        for (i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        sort(a+1, a+1+n); p = 1;
        ans = find(2, n);
        printf("%lld\n", ans);
    }
    return 0;
}