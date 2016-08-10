#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int x, k, n;

int main() {
    scanf("%d", &n);
    x = 0;
    while (n--) {
        scanf("%d", &k);
        x += k - 1;
        x = x % 2;
        if (x == 0)
            printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}