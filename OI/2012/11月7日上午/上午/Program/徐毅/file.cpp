#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char s[222], t[222];

struct data
{
    char name[22];
    int nxt[22];
} d[333];

bool cmp(int x, int y)
{
    return strcmp(d[x].name, d[y].name) == -1;
}

void print(int cur, int dep)
{
    for (int i = 1; i < dep; ++ i)
        printf("|    ");
    if (dep)
        printf("|----");
    puts(d[cur].name);
    sort(d[cur].nxt + 1, d[cur].nxt + d[cur].nxt[0] + 1, cmp);
    for (int i = 1; i <= d[cur].nxt[0]; ++ i)
        print(d[cur].nxt[i], dep + 1);
}

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int n, root = 0, size = 0;
    scanf("%d ", &n);
    for (int i = 0; i < n; ++ i)
    {
        gets(s);
        int len = strlen(s);
        s[len] = '/';
        s[len + 1] = 0;
        len = 0;
        int cur = root;
        for (int j = 0; s[j]; ++ j)
            if (s[j] == '/')
            {
                bool f = true;
                t[len] = 0;
                for (int k = 1; f && k <= d[cur].nxt[0]; ++ k)
                    if (!strcmp(d[d[cur].nxt[k]].name, t))
                    {
                        cur = d[cur].nxt[k];
                        f = false;
                    }
                if (f)
                {
                    strcpy(d[++ size].name, t);
                    d[cur].nxt[++ d[cur].nxt[0]] = size;
                    cur = size;
                }
                len = 0;
            }
            else
                t[len ++] = s[j];
    }
    print(1, 0);
    return 0;
}
