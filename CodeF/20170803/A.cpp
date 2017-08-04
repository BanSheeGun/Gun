#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int s, n, ans;
char ch;

int main() {
    scanf("%d", &n);
    getchar();
    s = 0;
    ans = 0;
    while (n--) {
        ch = getchar();
        if (ch == ' ') {
            ans = max(ans, s);
            s = 0;
        } else {
            if (ch >= 'A' && ch <= 'Z')
                ++s;
        }
    }
    ans = max(ans, s);
    printf("%d\n", ans);    
    return 0;
}