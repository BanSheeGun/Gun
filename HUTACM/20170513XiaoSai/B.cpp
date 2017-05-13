#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int n, a, b;

int main() {
    while (~scanf("%d%d%d", &n, &a, &b)) {
        n = n / gcd(a, b);
        if (n & 1)
            printf("Shuai seniors said,oh yeah,I was the most handsome!\n");
        else
            printf("TingTing said,ha ha,I was the most handsome!\n");
    }
    return 0; 
}