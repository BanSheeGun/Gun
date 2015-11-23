#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

char s[200],a;
int n,t,i,l;
bool ans;

int main()
{
    scanf("%d",&n);
    getchar();
    for (t = 1; t <= n; ++t) {
        stack<char> q;
        ans = 1;
        l = 0;
        while ((s[l]=getchar()) != '\n') {
            ++l;
        }
        s[l]='\0';
        for (i = 0; i < l; ++i) {
            if (s[i] == '(' || s[i] == '[') {
                q.push(s[i]);
            } else {
                if (q.empty()) {
                    ans = 0;
                    break;
                }

                if (s[i] == ')') {
                    a = q.top();
                    if (a == '(') {
                        q.pop();
                    } else {
                        ans = 0;
                        break;
                    }
                }

                if (s[i] == ']') {
                    a = q.top();
                    if (a == '[') {
                        q.pop();
                    } else {
                        ans = 0;
                        break;
                    }
                }
                if (s[i] != ')' && s[i] != ']') ans = 0;
            }
            if (ans == 0) break;
        }

        if (ans == 1 && q.size() == 0) printf("Yes\n");
            else printf("No\n");
    }

    return 0;
}
