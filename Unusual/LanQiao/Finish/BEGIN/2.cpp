#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

long long n , s;

int main() {
    scanf("%lld",&n);
    s = n * (n + 1) / 2;
    printf("%lld\n",s);
    return 0;
}
