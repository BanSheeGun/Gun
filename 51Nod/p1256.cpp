#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
 
int a, b, x, y;
 
int exgcd(int a,int b,int &x,int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return 0;
    }
    exgcd(b, a % b, x, y);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
    return 0;
}
 
int main()
{
    scanf("%d%d",&a, &b);
 
    exgcd(a, b, x, y);
    x = x % b;
    x = (x + b) % b;
 
    printf("%d\n",x);
    return 0;
}