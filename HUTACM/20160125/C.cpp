#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

struct ball
{
    char name[20];
    int num;
};

ball a[1010];
char b[20];
int n, i, top, ans, t;

int find() {
    for (int i = 1;i <= top; ++i) {
        if (strcmp(a[i].name,b) == 0)
            return i;
    }
    return 0;
}

int main()
{
    scanf("%d",&n);
    while (n != 0) {
        top = 0;
        for (i = 1;i <= n; ++i) {
            scanf("%s",b);
            t = find();
            if (t == 0) {
                ++top;
                strcpy(a[top].name, b);
                a[top].num = 1;
            } else {
                ++a[t].num;
            }
        }
        for (i = 1;i <= top; ++i)
            if (a[i].num > a[ans].num)
                ans = i;
        printf("%s\n",a[ans].name);
        scanf("%d",&n);
    }
    return 0;
}
