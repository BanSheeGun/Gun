#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;
int tt,n;
int p[10][10]={
    {1,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,0,1,1,0,1,1},
    {0,0,0,1,0,0,1,0,0,1},
    {1,0,0,0,1,1,1,1,1,1},
    {1,0,0,0,0,1,1,0,1,1},
    {0,0,0,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1,1,1},
    {1,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,0,0,0,0,0,1}
};
bool t[1000];
int a[1000];
int b[1000];
int c[1000];
int i,a1,a2,x,y,z;
int main() {
    for (i = 0;i <= 9; ++i)
        t[i] = 1;

    for (i = 10;i <= 99; ++i) {
        x = i / 10;
        y = i % 10;
        if (p[x][y]) t[i] = 1;
            else t[i] = 0;
    }

    for (i = 100;i <= 999; ++i) {
        x = i / 100;
        y = i / 10 % 10;
        z = i % 10;
        if (p[x][y] && p[y][z]) t[i] = 1;
            else t[i] = 0;
    }
    a[0] = 0;
    for (i = 1; i <= 999; ++i)
        if (t[i]) a[i] = i;
            else a[i] = a[i-1];
    b[999] = 999;
    for (i = 998; i >= 0; --i)
        if (t[i]) b[i] = i;
            else b[i] = b[i+1];
    for (n = 1;n <= 400; ++n) {
        a1 = abs(n - a[n]);
        a2 = abs(b[n] - n);
        if (a1 < a2) c[n] = a[n];
            else c[n] = b[n];
    }
    scanf("%d",&tt);
    while (tt--) {
        scanf("%d",&n);
        printf("%d\n",c[n]);
    }
    return 0;
}
