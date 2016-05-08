#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct D {
    int p;
    int l;
    int r;
    int d;
    int c[26];
} d[500010];

int head[500010];
int next[500010];
int e[500010];
int ff[500010];
int l,r,n,m,i,k,y,f,p;
char b[500010];
int t[500010];

int check() {
    int dd;
    for (dd = ff[y];d[dd].d <k;dd = d[dd].l) {
        if (dd==0) {
            printf("Yes\n");
            return 0;
        }
    }
    l = dd;
    for (dd = ff[y];d[dd].d <k;dd = d[dd].r) {
        if (dd==0) {
            printf("Yes\n");
            return 0;
        }
    }
    r = dd;    int odd = 0;
    for (int i = 0; i < 26; ++i)
        if ((d[r].c[i] - d[l-1].c[i]) % 2 == 1) ++odd;
    if (odd > 1) {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    return 0;
}

int main() {
    scanf("%d%d",&n, &m);
    for (i = 1; i < n; ++i) {
        scanf("%d", &f);
        e[i] = i+1;
        next[i] = head[f];
        head[f] = i;
    }
    scanf("%s",b);
    d[1].p = 1;
    d[1].d = 1;
    d[1].r = 0;
    ff[1] = 1;
    d[0].l = 0;
    d[0].r = 0;
    memset(d[1].c, 0, sizeof(d[1].c));
    memset(d[0].c, 0, sizeof(d[0].c));
    memset(t,0, sizeof(t));
    t[1] = 1;
    d[1].c[b[0] - 'a']++;
    for (f=1,p=1;f <= p; ++f) {
        d[f].l = p+1;
        for (k = head[d[f].p];k!=0;k = next[k]) {
            y = e[k];
            if (t[y]==1) continue;
            ++p;
            d[p] = d[f];
            d[f].r = p;
            d[p].p = y;
            d[p].d++;
            for (int j = 0; j < 26; ++j)
                d[p].c[j] = d[p-1].c[j];
            d[p].c[b[y-1] - 'a']++;
            d[p].r = 0;
            ff[y] = p;
            t[y] = 1;
        }
        if (d[f].r == 0)
            d[f].l = 0;
    }


    for (i = 1; i <= m; ++i) {
        scanf("%d%d",&y,&k);
        check();
    }
    return 0;
}
