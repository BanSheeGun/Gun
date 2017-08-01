#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int v1, v2, t1, t2, s1, s2, n;

inline int work(int v, int t) {
    return 2 * t + n * v;
}

int main() {
    scanf("%d", &n);
    scanf("%d%d%d%d", &v1, &v2, &t1, &t2);
    s1 = work(v1, t1);
    s2 = work(v2, t2);
    if (s1 == s2)
        puts("Friendship");
    else
        if (s1 < s2)
            puts("First");
        else
            puts("Second");
    return 0;
}