#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;

char a[20];
int l, t, i;

int main() {
    scanf("%s", a);
    l = strlen(a);
    t = 0;
    for (i = 0; i < l / 2; ++i) 
        if (a[i] != a[l - i - 1])
            ++t;
    if (t == 1 || (l & 1 && t == 0))
        printf("YES\n");
    else
        printf("NO\n");
    return 0; 
}