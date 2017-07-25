#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int l, T;
double d, c, b, c1, c2, A, B, C, t, ans;

int main() {
    d = sqrt(2.0) / 2.0;
    c = 1;
    b = 1.0 / 2;
    t = d * d + b * b - c * c;
    t = t / (2 * d * b);
    c1 = acos(-t);
    B = c1 * b * b / 2.0;
    t = (d + b + c) / 2.0;
    A = t * (t - d) * (t - b) * (t - c);
    A = sqrt(A);
    t = d * d - b * b + c * c;
    t = t / (2.0 * d * c);
    c2 = acos(t);
    C = c * c * c2 / 2;
    ans = A + B - C;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &l);
        d = ans * l * l * 4;
        printf("%.2lf\n", d);
    }
    return 0;
}