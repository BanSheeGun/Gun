#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int t, i, l, a, b;
char num[10000010];

int main() {
    t = 0;
    while (~scanf("%s", num)) {
        ++t;
        l = strlen(num);
        a = 0; b = 0;
        for (i = 0; i < l; ++i) {
            a = (a * 10 + num[i] - 48) % 73;
            b = (b * 10 + num[i] - 48) % 137;
        }
        if (a == 0 && b == 0) {
            printf("Case #%d: YES\n", t);
        } else {
            printf("Case #%d: NO\n", t); 
        }
    }
    return 0;
}