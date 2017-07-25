#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

char a[100010];
char b[100010];
bool t[300];
int l, i, n, lb, xx, now, nowl, nowr;

inline bool check(char a, char b) {
    if (a == b)
        return 1;
    if (a == '?' && t[b] == 1)
        return 1;
    return 0;
}

inline int pan() {
    scanf("%s", b);
    lb = strlen(b);
    if (xx == -1) {
        bool tmp = 1;
        now = -1;
        for (i = 0; i < l; ++i)
            if (check(a[i], b[now+1])) {
                now++;
            } else {
                tmp = 0;
                puts("NO");
                return 0;
            }
        if (tmp && now == lb-1)
            puts("YES");
        else
            puts("NO");
        return 0;
    }
    bool ans = 1;
    nowl = -1;
    for (i = 0; i < xx; ++i)
        if ((nowl+1 < lb) && check(a[i], b[nowl+1])) {
            nowl++;
        } else {
            ans = 0;
            puts("NO");
            return 0;
        }
    nowr = lb;
    for (i = l-1; i > xx; --i)
        if ((nowr-1 >= 0) && check(a[i], b[nowr-1])) {
            nowr--;
        } else {
            ans = 0;
            puts("NO");
            return 0;
        }
    for (i = nowl+1; i <= nowr-1; ++i)
        if (t[b[i]])
            ans = 0;
    if (ans && nowl < nowr) 
            puts("YES");
        else
            puts("NO");
    return 0;
}

int main() {
    scanf("%s", a);
    memset(t, 0, sizeof(t));
    l = strlen(a);
    for (i = 0; i < l; ++i)
        t[a[i]] = 1;
    
    scanf("%s", a);
    l = strlen(a);
    scanf("%d", &n);
    xx = -1;
    for (i = 0; i < l; ++i)
        if (a[i] == '*')
            xx = i;
    while (n--) {
        pan();
    }
    return 0;
}