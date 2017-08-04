#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 60010;
int now[N];
int la1[N];
int nx1[N];
int last[N];
int n, i, T, k;
double ans;

int main() {
    scanf("%d", &T);
    while (T--) {
        memset(now, 0, sizeof(now));
        memset(last, 0, sizeof(last));
        scanf("%d", &n);
        for (i = 1; i <= n; ++i) {
            scanf("%d", &k);
            last[i] = now[k];
            now[k] = i;
        }
        for (i = 1; i <= n; ++i) {
            la1[i] = i-1;
            nx1[i] = i+1;
        }
        ans = 1;
        for (i = 1; i <= n; ++i) {
            int thelast = last[i];
            nx1[la1[thelast]] = nx1[thelast];         
            la1[nx1[thelast]] = la1[thelast];
            int tmp = 0;
            int j = i;
            while (j != 0) {
                j = la1[j];
                ++tmp;
                ans = min(ans, (double)tmp / (i - j));
                if ((double)tmp/i > ans)
                    break;
            }       
        }
        printf("%lf\n", ans);
    }
    return 0;
}