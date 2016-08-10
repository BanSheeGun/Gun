#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cctype>
using namespace std;

int s[300010];
int head[300010];
int nxt[300010];
int n, q, t, p, a, c, k, mt;

inline int read() {
    int x=0;
    int f=1, hhh=getchar();
    while(!isdigit(hhh)) {
        if(hhh=='-')
            f=-1;
        hhh=getchar();
    }
    while(isdigit(hhh)) {
        x=x*10+hhh-'0';
        hhh=getchar();
    }
    return x*f;
}

inline void FastWrite(int a){
    char snum[20];
    int i = 0;
    do{
        snum[i++] = a%10+48;
        a/= 10;
    }while(a != 0);
    i = i-1;
    while(i >= 0) putchar(snum[i--]);
    putchar('\n');
}

int main() {
    n = read();
    memset(s, 0, sizeof(s));
    memset(head, 0, sizeof(head));
    p = read();
    a = 0; c = 0; mt = 0;
    while (p--) {
        q = read(); t = read();
        if (q == 1) {
            ++c; s[c] = 1;
            nxt[c] = head[t]; head[t] = c;
            ++a;
            FastWrite(a);
        } else if (q == 2) {
                for (k = head[t]; k != 0; k = nxt[k])
                    if (s[k] == 1) {
                        s[k] = 0; --a;
                    }
                head[t] = 0;
                FastWrite(a);
            } else {
                for (k = mt+1; k <= t; ++k)
                    if (s[k]) {
                        s[k] = 0; --a;
                    }
                mt = max(mt, t);
                FastWrite(a);
            }
    }
    return 0;
}