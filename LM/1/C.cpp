#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<algorithm>
using namespace std;

inline int readint() {  
    char c = getchar();  
    while(!isdigit(c)) c = getchar();  
    int x = 0;  
    while(isdigit(c)) {  
        x = x * 10 + c - '0';  
        c = getchar();  
    }  
    return x;  
}  

inline bool cmp(int a, int b) {
    return a > b;
}

int n, i, j, ans;
int a[200001];

int main() {
    n = readint();
    for (i = 1; i <= n; ++i)
        a[i] = readint();
    sort(a+1, a+1+n, cmp);
    ans = 0;
    for (i = 2; i <= n; ++i) {
        if (ans >= a[i]) break;
        for (j = 1; j < i; ++j)
            ans = max(ans, a[j] % a[i]);
    }
    printf("%d\n", ans);
    return 0;
}