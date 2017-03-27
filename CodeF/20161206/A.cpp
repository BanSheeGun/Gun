#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int a, ans;

int f(int n) {
    if (n == 1) return 8;
    if (n == 0) return 1;
    int t = f(n / 2);
    t = t * t % 10;
    if (n % 2 == 1)
        t = t * 1378 % 10;
    return t;
}

int main() {
    scanf("%d", &a);
    ans = f(a);
    printf("%d\n", ans);
    return 0;
}