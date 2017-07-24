#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int exgcd(int a, int b, int & x, int & y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int tmp = exgcd(b, a % b, x, y);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
    return tmp;
}

int a[4];
int m[4];
int ans, i, d;

int CRT() {
    int ans = 0;
    int M = 21252;
    for (i = 1; i <= 3; ++i) {
        int Mi = M / m[i];
        int t, y;
        exgcd(Mi, m[i], t, y);
        ans = (ans + a[i] * Mi * t) % 21252; 
    }
    return ans;
}

int main() {
    m[1] = 23, m[2] = 28, m[3] = 33;
    int T = 0;
    while (~scanf("%d%d%d%d", &a[1], &a[2], &a[3], &d), !(a[1] == -1&&a[2] == -1&&a[3] == -1 && d == -1)) {
        ans = CRT();
        ans  = (ans - d) % 21252;
        if (ans <= 0)
            ans += 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", ++T, ans);
    }
    return 0;
}