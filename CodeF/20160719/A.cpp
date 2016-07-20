#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct P {
    int x, num;
};

bool cmp(P a, P b) {
    return a.x < b.x;
}

P b[200010];
char a[200100];
int n, i, t, time;

int main() {
    scanf("%d", &n);
    scanf("%s", a);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &b[i].x);
        b[i].num = i-1;
    }
    sort(b+1, b+1+n, cmp);
    time = 1000000000;
    t = 0;
    for (i = 1; i < n; ++i) {
        if (b[i].x == b[i+1].x) {
            t = 1;
            time = 0;
            break;
        }
        if (a[b[i].num] == 'R' && a[b[i+1].num] == 'L') {
            t = 1; 
            time = min(time, b[i+1].x - b[i].x);
        }
    }

    if (t == 1)
        printf("%d\n", time / 2);
    else
        printf("%d\n", -1);
    return 0;
}