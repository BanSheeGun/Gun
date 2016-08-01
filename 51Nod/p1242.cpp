#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

const long long base = 1000000009;

struct Matrix {
    long long a[2][2];

    Matrix() {
        a[0][0] = 0; a[0][1] = 0;
        a[1][0] = 0; a[1][1] = 0;
    }

    inline Matrix operator * (const Matrix b) const {
        Matrix c;
        c.a[0][0] = (a[0][0] * b.a[0][0] + a[0][1] * b.a[1][0]) % base;
        c.a[0][1] = (a[0][0] * b.a[0][1] + a[0][1] * b.a[1][1]) % base;
        c.a[1][0] = (a[1][0] * b.a[0][0] + a[1][1] * b.a[1][0]) % base;
        c.a[1][1] = (a[1][0] * b.a[0][1] + a[1][1] * b.a[1][1]) % base;
        return c;
    }
};

long long n;
Matrix e, a;

inline Matrix f(long long n) {
    if (n == 1)
        return e;
    Matrix t = f(n / 2);
    t = t * t;
    if (n % 2 == 1)
        t = t * e;
    return t;
}

int main() {
    scanf("%lld", &n);
    if (n == 0)
        printf("0\n");
    else
        if (n == 1 || n == 2)
            printf("1\n");
        else {
            e.a[0][0] = 1; e.a[0][1] = 1;
            e.a[1][0] = 1; e.a[1][1] = 0;
            a = f(n - 2);
            long long ans = (a.a[0][0] + a.a[1][0]) % base;
            ans = (ans + base) % base;
            printf("%lld\n", (a.a[0][0] + a.a[1][0]) % base);
        }
    return 0;
}