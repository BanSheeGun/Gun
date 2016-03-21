#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<string> 
#include<algorithm> 
using namespace std;

int a[1011];
int n, i ,ans, x;

bool cmp(int a, int b) {
    return a < b; 
}

int main() {
    scanf("%d",&n);
    memset(a, 0 , sizeof(a));
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        a[x] = 1;
    }
    ans = 0;
    for (i = 1;i < 1001; ++i)
        if (a[i] + a[i+1] + a[i+2] == 3) {
            ans = 1;
            break;
        } 
    if (ans == 1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    } 
    return 0;
}
