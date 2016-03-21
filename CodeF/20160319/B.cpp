#include<cstdio>
#include<cstdlib>
#include<cstring> 
#include<string> 
#include<algorithm> 
using namespace std;

char aa[5];
char bb[4];
int ch[40][3];
int t[10];
int ans, n ,m ,i;

int dfs(int k) {
    if (k == n) {
        ++ans;
        return 0;
    }
    for (int i = 1;i <= m; ++i) {
        if (ch[i][0] == t[k]) {
            t[k+1] = ch[i][1];
            dfs(k+1);
        }
    }
    return 0;
}

int main() {
    scanf("%d%d",&n,&m);
    for (i = 1;i <= m;++i) {
        scanf("%s%s",aa,bb);
        ch[i][0] = bb[0] - 'a';
        ch[i][1] = aa[0] - 'a';
        ch[i][2] = aa[1] - 'a';
    }
    t[1] = 0;
    ans = 0;
    dfs(1);
    printf("%d\n",ans);
    return 0;
}
