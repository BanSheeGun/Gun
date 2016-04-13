#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 2300000;


int data[N];
int lc[N], rc[N], l[N], r[N];
int n, w, h, top, k;

inline bool can(int n, int k) {
    if (n == 0)
        return 1;
    return (w >= k + data[n]);
}

int find(int now, int k) {
    if (l[now] == r[now]) {
        data[now] += k;
        printf("%d\n", l[now]);
        return 0;
    }

    if (can(lc[now], k)) {
        if (lc[now] == 0) {
            ++top;
            l[top] = l[now];
            r[top] = (l[now] + r[now]) >> 1;
            lc[now] = top;
        }
        find(lc[now], k);
    } else {
        if (rc[now] == 0) {
            ++top;
            r[top] = r[now];
            l[top] = (l[now] + r[now]) / 2 + 1;
            rc[now] = top;
        }
        find(rc[now], k);
    }
    data[now] = min(data[lc[now]], data[rc[now]]);
    return 0;
}

int main() {
    while(~scanf("%d%d%d",&h,&w,&n)) {
        memset(data, 0, sizeof(data));
        memset(lc, 0, sizeof(lc));
        memset(rc, 0, sizeof(rc));

        top = 1;
        l[1] = 1;
        r[1] = h;
        while (n--) {
            scanf("%d", &k);
            if (w < data[1] + k) {
                printf("-1\n");
            } else {
                find(1, k);
            }
        }    
    }
    return 0;
}
