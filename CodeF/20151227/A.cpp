#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if (n % 2 == 0) {
        n = n / 2;
        n = (n - 1) / 2;
        printf("%d\n",n);
    } else {
        printf("0\n");
    }
    return 0;
}
