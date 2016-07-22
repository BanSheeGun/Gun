#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

#define eps 1e-8

struct Line {
    double x, y;
    int num;
};

inline bool cmp(Line a, Line b) {
    if (fabs(a.x - b.x) < eps)
        return a.y < b.y;
    return a.x < b.x;
}

Line a[50010];
bool ans[50010];
int n, top, i;
int s[50010];

inline double cross(int i, int j) {
    return (a[i].y - a[j].y) / (a[j].x - a[i].x);
}

inline int ins(int i) {
    while(top) {
        if (fabs(a[i].x - a[s[top]].x) < eps)
            --top;
        else 
            if (top > 1 && cross(i, s[top]) <= cross(s[top], s[top-1]))
                --top;
            else
                break;
    }
    s[++top] = i;
    return 0;
}

int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%lf%lf", &a[i].x, &a[i].y);
        a[i].num = i;
    }
    sort(a+1, a+1+n, cmp);
    top = 0;
    for (i = 1; i <= n; ++i) 
        ins(i);
    memset(ans, 0, sizeof(ans));
    for (i = 1; i <= top; ++i)
        ans[a[s[i]].num] = 1;
    for (i = 1; i <= n; ++i)
        if (ans[i])
            printf("%d ", i);
    return 0;
}
