#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int t,top1,top2,b,i;
char s[100011];
char ss[100011];
int a1[100011][3];
int a2[100011][3];

int p1(int n) {
    int i;
    int k = a1[n][1];
    for (i = 0; i < a1[n][2]; ++i)
        printf("%c",ss[k + i]);
}
int p2(int n) {
    int i;
    int k = a2[n][1];
    for (i = 0; i < a2[n][2]; ++i)
        printf("%c",ss[k + i]);
}
bool check() {
    int i;
    if (t == 0) return 0;
    if (s[0] == '0' && t > 1) return 0;
    for (i = 0;i < t; ++i)
        if (s[i] > '9' || s[i] < '0') return 0;
    return 1;
}

int main()
{
    top1 = 0;
    top2 = 0;
    t = 0;
    b = 0;
    while ((s[t] = getchar())!= '\n') {
        ss[b] = s[t];
        if (s[t] == ',' || s[t] == ';') {
            s[t] = '\0';
            if (check()) {
                ++top1;
                a1[top1][1] = b-t;
                a1[top1][2] = t;
            } else {
                ++top2;
                a2[top2][1] = b-t;
                a2[top2][2] = t;
            }
            t = -1;
        }
        ++t;
        ++b;
    }
            s[t] = '\0';
            ss[b] = '\0';
            if (check()) {
                ++top1;
                a1[top1][1] = b-t;
                a1[top1][2] = t;
            } else {
                ++top2;
                a2[top2][1] = b-t;
                a2[top2][2] = t;
            }
    if (top1 == 0) printf("-\n");
        else {
            printf("%c",34);
            p1(1);
            for (i = 2;i <= top1; ++i) {
                printf(",");
                p1(i);
            }
            printf("%c\n",34);
        }
    if (top2 == 0) printf("-\n");
        else {
            printf("%c",34);
            p2(1);
            for (i = 2;i <= top2; ++i) {
                printf(",");
                p2(i);
            }
            printf("%c\n",34);
        }

    return 0;
}
