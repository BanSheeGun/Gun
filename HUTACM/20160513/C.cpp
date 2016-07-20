#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

bool cmp(long long a, long long b) {
    return a < b;
}

long long a[100010];
long long b[100010];
long long l, r, ans, n, m, w, i;
long long t[100010][2];

long long check(long long k) {
    memset(t, 0, sizeof(t));
    int top = 0;
    int tail = 1;
    long long s = 0;
    long long mm = m;
    for (i = 1; i <= n; ++i) {
        b[i] = a[i];
    }
    for (i = 1; i <= n; ++i) {
        while (tail <= top && t[tail][0] + w - 1 <  i) {
            s -= t[tail][1];
            ++tail;
        }
        
        b[i] += s;
        if (b[i] < k) {
            ++top;
            t[top][0] = i;
            t[top][1] = k - b[i];
            mm -= t[top][1];
            s +=  t[top][1];
            if (mm < 0) 
                return 0;
            b[i] = k;
        }

        if (i + w - 1 == n) {
            ++top;
            t[top][0] = i;
            t[top][1] = mm;
            s += mm;
            mm = 0;
        }
    }
    return 1;
}

long long find(long long l, long long r) {
    if (l == r) {
        return l;
    }
    long long mid = (l + r + 1) >> 1;
    if (check(mid)) {
        return find(mid, r);
    } else {
        return find(l, mid - 1);
    }
}


int main() {
    scanf("%I64d%I64d%I64d", &n, &m, &w);
    for (i = 1; i <= n; ++i) {
        scanf("%I64d", &a[i]);
        b[i] = a[i];
    }
    sort(b+1, b+1+n, cmp);
    r = b[n] + m;
    ans = find(0, r);
    printf("%I64d\n",ans);
    return 0;
}
