#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 100000;
int f[N + 10];
int fa[N + 10];
int g[N + 10];
int n, m, k, i, T, x, y, tmp;

const int BUFSIZE= 100000000;
char Buf[BUFSIZE+1],*buf=Buf;
template<class T>
void scan(T&a){
for(a=0;*buf<'0'||*buf>'9';buf++);
while(*buf>='0'&&*buf<='9'){a=a*10+(*buf-'0');buf++;}}
int main() {
    fread(Buf,1,BUFSIZE,stdin);
    scan(T);
    while (T--) {
        scan(n); scan(m);
        for (i = 2; i <= n; ++i) {
            scan(fa[i]);
        }

        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for (i = n; i >= 2; --i) {
            f[fa[i]] += max(f[i], g[i]);
            f[fa[i]] = max(f[fa[i]], 1 + g[i] + g[fa[i]]);
            g[fa[i]] += max(f[i], g[i]);
        }
        tmp = max(f[1], g[1]);
        x = m / 2;
        x = min(tmp, x);
        y = m - x * 2;
        tmp = x + y;
        printf("%d\n", tmp);
    }
    return 0;
}