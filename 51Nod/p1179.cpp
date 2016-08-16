#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int n, k, i, nn, s;
int f[1000010];

int main() {
    memset(f, 0, sizeof(f));
    n = read(); nn = 0;
    while (n--) {
        k = read();
        s = sqrt(k);
        for (i = 1; i <= s; ++i) 
            if (k % i == 0) {
                f[i]++;
                f[k / i]++;
            }
        nn = max(nn, k);
        if (s * s == k) --f[s];
    }

    for (i = nn; i >= 1; --i) {
        if (f[i] > 1) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}