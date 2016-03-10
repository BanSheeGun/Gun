#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[21][3];
int t[21];
int ans[22];
int s, i, tt;

int pp() {
    ++tt;
    printf("%d: ", tt);
    for (int i = 1;i <= 21;++i)
        printf(" %d",ans[i]);
    printf("\n");
    return 0;
}

int sortt(int i) {
    if (a[i][2] < a[i][1])
        swap(a[i][2], a[i][1]);
    if (a[i][1] < a[i][0])
        swap(a[i][1], a[i][0]);
    if (a[i][2] < a[i][1])
        swap(a[i][2], a[i][1]);
    return 0;
}

int dfs(int step,int now) {
    ans[step] = now;
    if (step == 21) {
        if (now == s)
            pp();
        return 0;
    }

    for (int i = 0; i < 3; ++i) {
        if (t[a[now][i]] == 0) {
            t[a[now][i]] = 1;
            dfs(step + 1,a[now][i]);
            t[a[now][i]] = 0;
        }
    }
    return 0;
}

int main() {
    for (i = 1;i < 21; ++i) {
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        sortt(i);
    }
    tt = 0;
    scanf("%d",&s);
    while (s != 0) {
        memset(t, 0 ,sizeof(t));
        dfs(1, s);
        scanf("%d",&s);
    }
    return 0;
}
