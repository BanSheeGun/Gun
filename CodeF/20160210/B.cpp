#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int h,m,a;

int main()
{
    scanf("%d:%d",&h,&m);
    scanf("%d",&a);
    while (a--) {
        ++m;
        if (m == 60) {
            m = 0;
            ++h;
        }
        h = h % 24;
    }
    printf("%d%d:%d%d\n",h/10,h%10,m/10,m%10);
    return 0;
}
