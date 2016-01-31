#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main() {
    int a;
    scanf("%d",&a);
    if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}
