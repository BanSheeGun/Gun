#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long a[110], m[110];
int n, i;

void extend_Euclid(long long a, long long b, long long &x, long long &y) {  
    if(b == 0) {  
        x = 1;  
        y = 0;  
        return;  
    }  
    extend_Euclid(b, a % b, x, y);  
    long long tmp = x;  
    x = y;  
    y = tmp - (a / b) * y;  
} 

long long CRT(long long n) {  
    long long M = 1;  
    long long ans = 0;  
    for(long long i=1; i<=n; i++)  
        M *= m[i];  
    for(long long i=1; i<=n; i++) {  
        long long x, y;  
        long long Mi = M / m[i];  
        extend_Euclid(Mi, m[i], x, y);  
        ans = (ans + Mi * x * a[i]) % M;  
    }  
    if(ans < 0) ans += M;  
    return ans;  
}  
int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%lld%lld", &m[i], &a[i]);
    }
    printf("%lld\n", CRT(n));
    return 0;
}