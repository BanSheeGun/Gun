#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

char a[100010];
int l, i, t;

int main() {
    scanf("%s", a);
    l = strlen(a);
    t = 0;
    for (i = 0; i < l; ++i) {
        if (a[i] != 'a') {
            t = 1; a[i]--;
        } else {
            if (t == 1)
                break;
        } 
    }
    if (t == 0)
        a[l-1] = 'z';
    printf("%s\n", a);
    return 0;
}