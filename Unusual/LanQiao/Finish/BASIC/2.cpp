#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int i;

int main() {
    for (i = 0;i <= 31;++i) {
        printf("%d",i / 16 % 2);
        printf("%d",i / 8 % 2);
        printf("%d",i / 4 % 2);
        printf("%d",i / 2 % 2);
        printf("%d",i / 1 % 2);
        putchar('\n');
    }
    return 0;
}
