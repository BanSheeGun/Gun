#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int n, k, i, j;
char a[1000010];
int c[1000010];
int r[30];
int l[30];

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", a);
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    for (i = 0; i < n; ++i)
        if (l[a[i] - 'A'] == 0)
            l[a[i] - 'A'] = i+1;
    for (i = n-1; i >= 0; --i)
        if (r[a[i] - 'A'] == 0)
            r[a[i] - 'A'] = i+1;

    for (j = 0; j < 26; ++j)
        if (l[j] != 0)
            for (i = l[j]-1; i <= r[j]-1; ++i)
                c[i]++;

    for (i = 0; i < n; ++i)
        if (c[i] > k) {
            puts("YES");
            return 0;
        }
    puts("NO");
    return 0;
}