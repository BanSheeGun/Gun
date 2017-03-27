#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

long long a, b, c; 

int main() {
    while (~scanf("%I64d%I64d", &a, &b)) {
        c = 1;
        while (--a) {
            b /= 2;
            c *= 2;
            if (b == 0) break;
        }
        b %= 2;
        if (b == 0)
            printf("0\n");
        else
            printf("%I64d\n", c);
    }
    return 0; 
}