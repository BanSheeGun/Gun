#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, TT, T;

int main() {
    scanf("%d", &T); TT = 0;
    while (T--) {
        TT++;
        scanf("%d", &n);
        printf("Case #%d: %d\n", TT, 2*n-1);
    }
    return 0;
}