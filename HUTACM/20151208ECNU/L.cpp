#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;
int tt;

struct alien
{
    int a,b,d;
};

bool cmp(alien a,alien b) {
    return a.d<b.d;
}

alien a[310];
int main() {
    scanf("%d",&tt);
    while (tt--) {
        scanf("%d",&n);
        for (i = 1;i <= n; ++i) {
            scanf("%d%d%d",a[i].a,a[i].b,a[i].c);
        }
    }
    return 0;
}
