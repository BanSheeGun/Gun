#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int y, m, d, T, t;

inline bool pan(int year) {
    return (year%4==0&&year%100!=0)||(year%400==0);
}

inline int cwd(int y, int m, int d) {
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d-%d-%d", &y, &m, &d);
        int now = cwd(y, m, d);
        do {
            ++y;
            bool p = !pan(y);
            if (m == 2 && d == 29 && p)
                t = -1;
            else
                t = cwd(y, m, d);
        } while (t != now);
        printf("%d\n", y);
    }
    return 0;
}