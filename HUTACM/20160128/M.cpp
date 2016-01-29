#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int a[1010];
int n,i,t;

bool cmp(int a,int b) {
    return a < b;
}

int main()
{
    scanf("%d",&n);
    for (i = 0;i < n;++i) {
        scanf("%d",&a[i]);
    }
    sort(a,a + n,cmp);
    printf("%d\n",a[n / 2]);
    return 0;
}
