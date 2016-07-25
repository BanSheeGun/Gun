#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

char b[100010];
int a[100010];
int t[60];
int ans, l, r, n, now, s, i;

int ask() {
    while (r <= n) {
        if (now != s) {
            if  (r == n)
                return 0;
            ++r;
            if (t[a[r]] == 0) ++now;
            ++t[a[r]];
        } else {
            --t[a[l]];
            if (t[a[l]] == 0) --now;
            ++l;
        }
        if (now == s) {
            ans = min(ans, r-l+1);
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", b);
    for (i = 1; i <= n; ++i) {
        if ('a' <= b[i-1] && b[i-1] <= 'z')
            a[i] = b[i-1] - 'a' + 1;
        else
            a[i] = b[i-1] - 'A' + 27;
    }
    memset(t, 0, sizeof(t));
    for (i = 1; i <= n; ++i) {
        ++t[a[i]];
    }

    s = 0;
    for (i = 1; i <= 52; ++i) {
        if (t[i] != 0) {
            ++s;
        }
    }
    ans = n;
    l = 1; r = 0; now = 0;
    memset(t, 0, sizeof(t));
    ask();
    printf("%d\n", ans);
    return 0;
}