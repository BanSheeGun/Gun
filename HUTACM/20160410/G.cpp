#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;

int f[1010][1010];
char p[1010], q[1010];
int la, lb, i, j;

int main() {
    while (~scanf("%s%s",p,q)) {
        la = strlen(p);
        lb = strlen(q);
        memset(f, 0, sizeof(f));
        
        for (i = 1; i <= la; ++i)
            for (j = 1; j <= lb; ++j) { 
                f[i][j] = max(f[i][j], f[i-1][j-1]);
                f[i][j] = max(f[i][j], f[i-1][j]);
                f[i][j] = max(f[i][j], f[i][j-1]);
                f[i][j] = max(f[i][j], f[i-1][j-1] + (int)(p[i-1] == q[j-1]));
            } 
        printf("%d\n", f[la][lb]);
    }   
    return 0;
}
