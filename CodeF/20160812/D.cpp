#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

int lc[10000000];
int rc[10000000];
int sum[10000000];
int a[40], b[40];
int m, c, i, ans, tot;
char s[5];

int add(int now, int k, int de) {
    if (k == -1) {
        sum[now] += de;
        return 0;
    }
    if (a[k] == 1) {
        if (lc[now] == 0) {
            ++tot;
            lc[now] = tot;
        }
        add(lc[now], k-1, de);
    } else {
        if (rc[now] == 0) {
            ++tot;
            rc[now] = tot;
        }
        add(rc[now], k-1, de);
    }
    sum[now] = 0;
    if (lc[now]) sum[now] += sum[lc[now]];
    if (rc[now]) sum[now] += sum[rc[now]];
    return 0;
}

int work(int n) {
    int i, tmp;
    for (i = 29; i >= 0; --i) {
        tmp = 1 << i;
        tmp = tmp & n;
        if (tmp > 0)
            a[i] = 1;
        else
            a[i] = 0;
    }
}

int find(int now, int k) {
    if (k == -1) return 0;
    if (a[k] == 1) {
        if (rc[now] != 0 && sum[rc[now]] != 0) {
            b[k] = 0;
            find(rc[now], k-1);
        } else {
            b[k] = 1;
            find(lc[now], k-1);
        }
    } else {
        if (lc[now] != 0 && sum[lc[now]] != 0) {
            b[k] = 1;
            find(lc[now], k-1);
        } else {
            b[k] = 0;
            find(rc[now], k-1);
        }
    }
    return 0;
}

int main() {
    memset(lc, 0, sizeof(lc));
    memset(rc, 0, sizeof(rc));
    lc[0] = 1; rc[0] = 2; tot = 2;
    work(0);
    add(0, 29, 1);
    scanf("%d", &m);
    while (m--) {
        scanf("%s", s);
        scanf("%d", &c);
        work(c);
        if (s[0] == '+') {
            add(0, 29, 1);
        } else {
            if (s[0] == '-') {
                add(0, 29, -1);
            } else {
                find(0, 29);
                ans = 0;
                for (i = 0; i <= 29; ++i) 
                    if (b[i])
                        ans += 1 << i;
                ans = ans ^ c;
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}