#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

int t, ans ,aa,i;
char c;
char z[2000000];

int main()
{
    t = 0;
    ans = 0;
    aa = 0;
    while ((c = getchar()) != '\n') {
        if (t == 0) { 
            if (c == '<' ||c == '(' ||c == '{' ||c == '[') {
                ++t;
                z[t] = c;
            } else {
                aa = 1;
                break;
            }
            if (aa) break;
        } else {
            if (c == '<' ||c == '(' ||c == '{' ||c == '[') {
                ++t;
                z[t] = c;
            } else {
                if (t == 0) {
                    aa = 1;
                    break;
                }
                if (z[t] == '<' && c != '>') ++ans;
                if (z[t] == '[' && c != ']') ++ans;
                if (z[t] == '{' && c != '}') ++ans;
                if (z[t] == '(' && c != ')') ++ans;
                --t;
            }
            if (aa) break;
        }
    }
    if (aa || t != 0) {
        printf("Impossible\n");
    } else {
        printf("%d\n",ans);
    }
    return 0;
}
