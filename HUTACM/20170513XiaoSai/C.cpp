#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

int a[600];
int s, ss, n, l, r, i, ans;

int main() {
    while (~scanf("%d", &n)) {
        memset(a, 0, sizeof(a));
        while (n--) {
            scanf("%d%d", &l, &r);
            a[l] += 1;
            a[r+1] -= 1;
        }

        ans = 0;
        s = a[0];
        ss = a[0];
        for (i = 1; i <= 500; ++i) {
            s += a[i];
            if (s > ss) {
                ss = s;
                ans = i;
            }
        }
        printf("%d\n", ss);
    }
    return 0; 
}