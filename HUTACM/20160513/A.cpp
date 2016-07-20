#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;

int n, m, day, ans;

int main() {
    scanf("%d%d",&n ,&m);
    day = 0;
    ans = 0;
    while (n != 0) {
        ++ans;
        --n;
        ++day;
        if (day % m == 0)
            ++n;
    }
    printf("%d\n", ans);
    return 0;
}
