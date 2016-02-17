#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int MOD = 7;

struct Matrix
{
    int m[2][2];
    Matrix () {
        memset(m, 0, sizeof(m));
    }
    Matrix (int a,int b,int c,int d) {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }
    Matrix operator * (Matrix &B) {
        Matrix C;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k) {
                    C.m[i][j] += m[i][k] * B.m[k][j];
                    C.m[i][j] %= MOD;
                }
        return C;
    }
};

Matrix E(1,0,0,1);
Matrix A;
int a,b,n;

Matrix Pow(int n) {
    if (n == 0)
        return E;
    if (n == 1)
        return A;
    Matrix t;
    t = Pow(n / 2);
    t = t * t;
    if (n & 1)
        t = t * A;
    return t;
}

int main() {
    scanf("%d%d%d",&a,&b,&n);
    a = (a % MOD + MOD) % MOD;
    b = (b % MOD + MOD) % MOD;
    A.m[0][0] = a;
    A.m[0][1] = 1;
    A.m[1][0] = b;
    A.m[1][1] = 0;
    if (n == 1) {
        printf("%d\n",1);
    } else {
        Matrix ans = Pow(n - 2);
        n = ans.m[0][0] + ans.m[1][0];
        n %= MOD;
        printf("%d\n",n);
    }
    return 0;
}
