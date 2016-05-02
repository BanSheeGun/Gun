#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int a[1010][2010];
int w[2010];
int n, i, j, k, m;

bool cmp(int a, int b) {
    return a < b;
}

int ff(int i, int j){
    if(i * 2 > j)
        return 1000000000;
    if(i == 0)
        return 0;
    return a[i][j];
}

int main() {
    while(~scanf("%d%d", &n, &k)) {
        for (i = 1; i <= n; ++i)
            scanf("%d", &w[i]);
        sort(w+1, w+1+n, cmp);
        for (i = 1; i <= n; ++i)
            w[i] = (w[i+1] - w[i]) * (w[i+1] - w[i]);

        for (i = 1; i <= k; ++i){
            for (j = i * 2; j <= n; ++j)
                a[i][j] = min(ff(i-1, j-2) + w[j-1], ff(i, j-1));
        }
        printf("%d\n", a[k][n]);
    }
    return 0;
}
