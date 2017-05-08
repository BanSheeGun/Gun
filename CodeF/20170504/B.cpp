#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    while (n--) {
        if (n % 4 > 1)
            putchar('a');
        else
            putchar('b');
    }
    putchar('\n');
    return 0; 
}