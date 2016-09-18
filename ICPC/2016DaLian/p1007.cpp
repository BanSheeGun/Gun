#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

long long n, m;

int main() {
    while (~scanf("%lld%lld", &m, &n)) {
        if ((m*m/4) <= n)
            printf("T\n");
        else
            printf("F\n");
    }
    return 0;
}