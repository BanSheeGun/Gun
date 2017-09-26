#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int n, T, ans, i;
int nxt[20];
int t[20];
char a[20];
char b[20];
int flag, sum;

int dfs(int n) {
    ++sum;
    if (a[0]-'0' ==n) flag =1;
    t[n] = 1;
    if (t[nxt[n]] == 0)
        dfs(nxt[n]);
    return 0;
}

int main() {
    while (~scanf("%d", &n)) { 
        for (T = 1; T <= 5; ++T) {
            scanf("%s", a);
            scanf("%s", b);
            memset(nxt, 0, sizeof(nxt));
            for (i = 0; i < n; ++i)
                nxt[a[i] - '0'] = b[i] - '0';
            memset(t, 0, sizeof(t));
            ans = 0;
            for (i = 1; i <= n; ++i)
                if (t[i] == 0 && nxt[i] != i) {
                    flag = 0;
                    sum = 0;
                    dfs(i);
                    if (flag)
                        ans+=sum-1;
                    else
                        ans+=sum+1;
                }
            printf("%d\n", ans);
        }
    }
    return 0;
}