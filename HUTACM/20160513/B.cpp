#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

long long a, b, c, i, n, m, top,s ,x;
long long ans[100];

bool cmp(long long a, long long b) {
    return a < b;
}

int main() {
    scanf("%I64d%I64d%I64d", &a, &b, &c);
    top = 0;
    for (s = 1; s <= 90; ++s) {
        x = 1;
        for (i = 1; i <= a; ++i)
            x = x * s;
        x = x * b;
        x = x + c;
        n = x;
        m = 0;
        while (n != 0) {
            m += n % 10;
            n /= 10;
        }
        if (s == m && x > 0 && x < 1000000000) {
            ++top;
            ans[top] = x;
        }
    }

    sort(ans+1,ans+1+top,cmp);
    printf("%I64d\n",top);
    if (top != 0) {
        for (i = 1; i < top; ++i)
            printf("%I64d ",ans[i]);
        printf("%I64d\n",ans[top]);
    }
    return 0;
}
