#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int T, n, i;
double R, tmpa, tmpb;
double l[20];
double r[20];

int main() {
    scanf("%d", &T);
    scanf("%lf", &R);
    l[0] = -R;
    r[0] = R;
    for (i = 1; i <= 10; ++i) {
        l[i] = l[i-1] + 2 * r[i-1];
        tmpa = 3 * R * R  + l[i] * l[i] - 2 * R * l[i] * sqrt(3);
        tmpb = 2 * sqrt(3) * R  + 2 * R - 2 * l[i];
        r[i] = tmpa / tmpb;
    }
    while (T--) {
        scanf("%d", &n);
        printf("%d %d\n", n, (int)r[n]);
    }
    return 0;
}