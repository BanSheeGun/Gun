#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

struct L {
    int m[100100];

    L() {
        memset(m, 0, sizeof(m));
    }
};

char s[100010];
int k[30];
int i, j, l, n, maxl;
L a[26];
ll ans, tmp;
bool us[30];

inline bool cmp(int x, int y) {
    int i;
    if (a[x].m[0] != a[y].m[0])
        return a[x].m[0] > a[y].m[0];
    for (i = a[x].m[0]; i > 0; --i)
        if (a[x].m[i] != a[y].m[i])
            return a[x].m[i] > a[y].m[i];
    return 0;
}


int main() {
    int T = 0;
    while (~scanf("%d", &n)) {
        memset(us, 0, sizeof(us));
        for (i = 0; i <= 25; ++i)
            memset(a[i].m, 0, sizeof(a[i].m));
        while (n--) {
            scanf("%s", s);
            l = strlen(s);
            us[s[0] - 'a'] = 1;
            for (i = 0; i < l; ++i) {
                a[s[i] -'a'].m[l - i]++;
                a[s[i] -'a'].m[0] = max(a[s[i] -'a'].m[0], l-i);
            }
        }

        maxl = 0;

        for (i = 0; i <= 25; ++i) {
            k[i] = i;
            for (j = 1; j <= a[i].m[0]; ++j) {
                a[i].m[j+1] += a[i].m[j] / 26;
                a[i].m[j] %= 26;
            }
            while (a[i].m[a[i].m[0] + 1] != 0) {
                ++a[i].m[0];
                a[i].m[a[i].m[0] + 1] = a[i].m[a[i].m[0]] / 26;
                a[i].m[a[i].m[0]] %= 26;
            }
            maxl = max(maxl, a[i].m[0]);
        }
        sort(k, k + 26, cmp);
        ans = 0;
        tmp = 1;
        int ze = 25;
        while (us[k[ze]] && ze > 0)
            ze--;
        for (i = ze; i <= 25; ++i)
            k[i] = k[i+1];

        for (i = 1; i <= maxl; ++i) {
            for (j = 0; j < 25; ++j) {
                ans += (ll)(25 - j) * tmp * a[k[j]].m[i] % mod;
                ans %= mod;
            }
            tmp = tmp * 26 % mod;
        }
        printf("Case #%d: %lld\n", ++T, ans);
    }
    return 0;
}