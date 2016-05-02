#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;

const double PI = acos(-1.0);

struct Point
{
    int x,y;

    inline Point operator - (const Point &B) const {
        Point C;
        C.x = x - B.x;
        C.y = y - B.y;
        return C;
    }

    inline int operator * (const Point &B) const {
        return x * B.x + y * B.y;
    }

    inline int operator ^ (const Point &B) const {
        return x * B.y - y * B.x;
    }

    int len2() {
        return x * x + y * y;
    }
};

bool cmp(Point x,Point y){
    if (x.x==y.x) return x.y<y.y;
    return x.x<y.x;
}

Point a[50010];
Point s[50010];
int n, i, top;

int main(){
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    sort(a, a+n, cmp);
    top = 0;
    for (i = 0;i < n; ++i) {
        while (top > 1 && ((s[top-1] - s[top-2]) ^ (a[i] - s[top-2])) <= 0)
            top--;
        s[top++] = a[i];
    }
    int k = top;
    for (i = n-2; i >= 0; --i) {
        while (top > k && ((s[top-1] - s[top-2]) ^ (a[i] - s[top-2])) <= 0)
            top--;
        s[top++] = a[i];
    }
    if (n>1) top--;

    int m = top - 1;
    int q=1;
    int ans=0;
    for(i = 0; i <= m; i++) {
        while(((s[i+1] - s[i]) ^ (s[q+1] - s[i]) > ((s[i+1] - s[i]) ^ (s[q] - s[i])))
            q = (q+1) % m;
        ans=max(ans , max((s[i] - s[q]).len2(), (s[i+1] - s[q+1]).len2()));
    }

    printf("%d\n",ans);
    return 0;
}