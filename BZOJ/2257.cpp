/**************************************************************
    Problem: 2257
    User: Gunpowder
    Language: C++
    Result: Accepted
    Time:10916 ms
    Memory:78960 kb
****************************************************************/
 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
 
ll a[10000000];
 
inline bool cmp(const ll & a,const ll & b) {
    return a > b;
}
 
int n, k, i, top, tmp;
ll p;
 
int main() {
    scanf("%d%d", &n, &k);
    top = 0;
    while (n--) {
        scanf("%lld", &p);
        for (i = 1; i <= sqrt(p); ++i)
            if (p % i == 0) {
                a[++top] = i;
                if (p / i != i)
                    a[++top] = p / i;
            }
    }
    a[0] = 0;
    sort(a+1, a+1+top, cmp);
    tmp = 0;
    for (i = 1; i <= top; ++i) {
        if (a[i] == a[i-1]) {
            ++tmp;
        } else {
            tmp = 1;
        }
        if (tmp >= k) {
            printf("%lld\n", a[i]);
            return 0;
        }
    }
    return 0;
}