#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

struct aa {
    int a, num;
};

bool cmp(aa a, aa b) {
    return a.a < b.a;
}

aa a[110];
int n, i;

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i].a);
        a[i].num = i+1;
    }

    sort(a, a+n, cmp);
    for (i = 1; i <= n/2 ; ++i) {
            printf("%d %d\n", a[i-1].num, a[n-i].num);
    }
    return 0;
}