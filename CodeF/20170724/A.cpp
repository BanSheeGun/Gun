#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n, k;

int main() {
    scanf("%lld%lld", &n, &k); 
    if ((n / k) & 1)
        puts("YES");
    else
        puts("NO");
    return 0;
}