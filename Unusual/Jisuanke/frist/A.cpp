#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

char a[7][7];
int d, i, j;

int main() {
    scanf("%d", &d);
    for (i = 0; i <= 6; ++i) {
        for (j = 0; j <= 6; ++j)
            a[i][j] = ' ';
    }
    a[0][0] = '+';
    a[0][6] = '+';
    a[6][0] = '+';
    a[6][6] = '+';
    for (i = 1; i <= 5; ++i) {
        a[i][0] = '|';
        a[i][6] = '|';
        a[0][i] = '-';
        a[6][i] = '-';
    }
    if (d >= 90) {
        a[1][4] = '4';
        a[1][5] = 'G';
    } else {
        if (d >= 60) {   
            a[1][4] = '3';
            a[1][5] = 'G';
        } else {
            a[1][5] = 'E';
        }
    }
    for (i = 1; i <= d / 20; ++i)
        for (j = 1; j <= i; ++j)
            a[i][j] = '-';

    for (i = 0; i <= 6; ++i) {
        for (j = 0; j <= 6; ++j)
            putchar(a[i][j]);
        puts("");
    }
    return 0; 
}