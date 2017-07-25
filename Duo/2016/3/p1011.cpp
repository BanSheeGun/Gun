#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

bool v[200010];
int ax[200010];
int ay[200010];
int T, n, m, i, nn, x, y;

inline bool find() {
    int i, j;
    memset(v, 0, sizeof(v));
    for (i = 1; i < n; ++i)
        for (j = i+1; j <= n; ++j) {
            int d = abs(ax[i] - ax[j]) + abs(ay[i] - ay[j]);
            if (v[d])
                return 1;
            v[d] = 1;
        } 
    return 0;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        nn = 0;
        for (i = 1; i <= n; ++i) {
            scanf("%d%d", &x, &y);
            if (x <= m && y <= m) {
                ++nn;
                ax[nn] = x;
                ay[nn] = y;
            }
        }
        n = nn;

        if (find()) 
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}