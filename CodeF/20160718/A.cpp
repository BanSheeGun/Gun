#include<cstdio>

using namespace std;

int n, a, sum, i;

int main() {
    scanf("%d", &n);
    if (n == 1) {
        scanf("%d", &a);
        if (a == 0) {
            printf("NO\n");
            return 0;
        }
        printf("YES\n");
        return 0;
    }
    sum = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &a);
        sum += a;
    }
    if (sum == n - 1) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}