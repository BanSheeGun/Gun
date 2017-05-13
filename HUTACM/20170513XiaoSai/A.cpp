#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a, sum, n;

int main() {
    while (~scanf("%d", &n)) {
        sum = 0;
        while (n--) {
            scanf("%d", &a);
            if (a > 0)
                sum += a;
        }
        printf("%d\n", sum);
    }
    return 0; 
}