#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n, s, k, i;
char a;

int main() {
    s = 0; n = 0;
    while ((a = getchar()) != '\n') {
        if ('0' <= a && a <= '9') {
            k = a - '0';
        } else {
            k = a - 'A' + 10;
        }
        s = max(s, k);
        n += k;
    }
    for (i = max(s, 1); i <= 35; ++i)
        if (n % i == 0) {
            printf("%d\n", i+1);
            return 0;
        } 
    printf("No Solution\n");
    return 0;
}