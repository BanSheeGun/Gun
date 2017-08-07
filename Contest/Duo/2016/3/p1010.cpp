#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

double a, v1, v2, v, ans;
int t;

int main() {
    while (~scanf("%lf%lf%lf", &a, &v1, &v2)) {
        if (a == 0) {
            printf("0\n");
            continue;
        }
        if (v1 <= v2) {
            printf("Infinity\n");
        } else {
            ans = v1 * v1 - v2 * v2;
            ans = v1 * a / ans;
            printf("%lf\n", ans);
        }
    }
    return 0;
}