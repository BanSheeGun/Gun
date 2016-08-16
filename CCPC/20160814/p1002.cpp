#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod = 2;
int t[2005];
int p[400];
int a[400][400];
int pt, i, j, n;
ll k, ans, aa;

inline ll f(ll n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    ll t = f(n / 2);
    t = t * t % 1000000007;
    if (n % 2 == 1)
        t = t * 2;
    t = t % 1000000007;
    return t;
}

inline ll Gauss(int lie, int hang){
    int r = 0, c = 0;
    for(; r < lie && c < hang; ++r, ++c){
        int mx = r;
        for(int i = r+1; i < lie; ++i){
            if(abs(a[i][c]) > abs(a[mx][c])) mx = i;
        }
        if(mx != r) swap(a[mx], a[r]);
        if(a[r][c] == 0){ r--; continue; }
        for(int i = r+1; i < lie; ++i){
            if(!a[i][c]) continue;
            int tmp1 = a[r][c], tmp2 = a[i][c];
            for(int j = c; j <= hang; ++j){
                a[i][j] = (a[i][j]*tmp1 - a[r][j]*tmp2)%mod;
                if(a[i][j] < 0) a[i][j] += mod;
            }
        }
    }
    for(int i = r; i < lie; ++i){
        if(a[i][hang]) return 0;
    }
    ll aaa = f(hang-r)-1;
    if (aaa < 0) aaa += 1000000007;
    return aaa;
}


int main() {    
    memset(t, 0, sizeof(t));
    pt = 0;
    for (i = 2; i < 2005; ++i) {
        if (t[i] == 0) {
            ++pt; p[pt] = i;
            for (j = 2 * i; j < 2005; j = j + i) {
                t[j] = 1;
            }
        }
    }
    int TT;
    scanf("%d", &TT); 
    for (int T = 1; T <= TT; ++T) {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; ++i) {
            scanf("%lld", &k);
            for (j = 1; j <= pt; ++j) 
                while (k % p[j] == 0) {
                    ++a[j-1][i]; k /= p[j];
                    a[j-1][i] %= 2;
                }
            }

        ans = Gauss(pt, n);
        printf("Case #%d:\n", T);
        printf("%lld\n", ans);
    }
    return 0;
}