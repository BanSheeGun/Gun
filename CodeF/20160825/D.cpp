#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;

ll a00, a01, a11, a10, s1, s0, i;
ll aa, ab, ac, ad;
char a[100010];

inline ll check(ll a) {
    ll tmp = 1 + 8 * a;
    tmp = sqrt(tmp);
    tmp = (1 + tmp) / 2;
    if (tmp * tmp - tmp == a * 2)
        return tmp;
    else 
        return 0;
}

int main() {
    scanf("%lld%lld%lld%lld", &a00, &a01, &a10, &a11);
    s0 = check(a00);
    s1 = check(a11);
    if (a01 + a10 == 0) {
        if (s1 == 1) s1 = 0;
        else if (s0 == 1) s0 = 0;
    }
    if (s1 == 0 && s0 == 0) {
        printf("Impossible\n");
        return 0;
    }
    if (s1 * s0 != a01 + a10) {
        printf("Impossible\n");
        return 0;
    }
    aa = a00; ab = a01; ac = a10; ad = a11;
    i = -1;
    while (a10 != 0) {
        if (a10 >= s0) {
            a10 -= s0;
            ++i; a[i] = '1';
            --s1;
        } else {
            while (s0 > a10) {
                ++i; a[i] = '0';
                --s0;
            }
        }
    }
    while (s0 != 0) {
        ++i; a[i] = '0';
        --s0;
    }
    while (s1 != 0) {
        ++i; a[i] = '1';
        --s1;
    }
    ++i; a[i] = '\0';
    s1 = 0; s0 = 0;
    a00 = aa; a01 = ab; a10 = ac; a11 = ad;
    for (int j = 0; j < i; ++j) {
        if (a[j] == '0') {
            a00 -= s0;
            a10 -= s1;
            ++s0;
        } else {
            a01 -= s0;
            a11 -= s1;
            ++s1;
        }
    }
    if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0)
        printf("%s\n", a);
    else
        printf("Impossible\n");
    return 0;
}