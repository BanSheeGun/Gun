#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct q {
    int x;
    int rank;
};

bool cmp(q a,q b) {
    return a.x < b.x;
}

q a[10001];
double ans[10001], sum;
int t, i, now;

int main() {
    scanf("%d",&t);
    for (i = 1;i <= t; ++i) {
        scanf("%d",&a[i].x);
        a[i].rank = i;
    }

    sort(a+1, a+1+t, cmp);
    now = 1;
    sum = 0;
    i = 1;
    while (now <= t) {
        sum += 1.0 / i;
        while (a[now].x == i && now <= t) {
            ans[a[now].rank] = sum;
            ++now;
        }
        ++i;
    }

    for (i = 1;i <= t; ++i)
        printf("Case %d: %.9lf\n",i,ans[i]);
    return 0;
}
