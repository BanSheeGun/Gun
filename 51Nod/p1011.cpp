#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

inline int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int a, b;

int main() {
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b));
    return 0;
}