#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

int a[1010];
int n, i, j;

int main() {
    a[1000] = 11;
    a[1] = 3; a[2] = 3; a[3] = 5; a[4] = 4; a[5] = 4;
    a[6] = 3; a[7] = 5; a[8] = 5; a[9] = 4; a[10] = 3;
    a[11] = 6; a[12] = 6; a[13] = 8; a[14] = 8; a[15] = 7;
    a[16] = 7; a[17] = 9; a[18] = 8; a[19] = 8; a[20] = 6;
    a[30] = 6; a[40] = 5; a[50] = 5; a[60] = 5; a[70] = 7;
    a[80] = 6; a[90] = 6;
    for (i = 2; i <= 9; ++i)
        for (j = 1; j <= 9; ++j)
            a[i * 10 + j] = a[i * 10] + a[j];
    for (i = 1; i <= 9; ++i)
        a[i * 100] = 7 + a[i];
    for (i = 1; i <= 9; ++i)
        for (j = 1; j <= 99; ++j)
            a[i*100 + j] = a[i*100] + 3 + a[j]; 

    a[0] = 0;
    for (i = 1; i <= 1000; ++i) 
        a[i] = a[i-1] + a[i];
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &i);
        printf("%d\n", a[i]);
    }
    return 0;
}