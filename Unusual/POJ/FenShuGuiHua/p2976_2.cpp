//Dinkelbach
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

struct S
{
    double a;
    double b;
    double d;
};

S s[1010];
int n ,i ,k;
double ans, eps = 0.000001;

bool cmp(S a, S b) {
    return a.d > b.d;
}

double solve() {
    double t, l, aa, bb;
    t = 1000;
    do {
        l = t;
        aa = 0;
        bb = 0;
        for (int i = 0;i < n; ++i)
            s[i].d = s[i].a - l * s[i].b;
        sort(s, s + n, cmp);
        for (int i = 0; i < n-k; ++i) {
            aa += s[i].a;
            bb += s[i].b;
        }
        t = aa / bb;
    } while (t + eps < l || l + eps < t);
    return l;
}

int main() {
    scanf("%d%d", &n, &k);
    while (n != 0 || k != 0) {
        for (i = 0;i < n; ++i)
            scanf("%lf", &s[i].a);
        for (i = 0;i < n; ++i)
            scanf("%lf", &s[i].b);

        ans = solve() * 100;
        printf("%.0f\n", ans);
        scanf("%d%d", &n, &k);
    }
    return 0;
}
