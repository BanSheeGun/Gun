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
    for (i = 10;i <= 99;++i) {
        printf("%d",i);
        printf("%d",i % 10);
        printf("%d\n",i / 10);
    }
    return 0;
}
