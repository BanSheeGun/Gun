#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

int a, b, c, d, i;

int main() {
    scanf("%d%d", &b, &a);
    scanf("%d%d", &d, &c);
    for (i = 0; i <= max(d+1, c+1); ++i) {
        if (a >= c) {
            if ((a - c) % d == 0) {
                printf("%d\n", a);
                return 0;
            }
        }
        a += b;
    }
    printf("-1\n");
    return 0; 
}