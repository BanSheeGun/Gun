#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
    int tt,n,i,j,a,b,q,z;
    bool t;
    scanf("%d",&tt);
    while (tt--) {
        scanf("%d",&n);
        z = n * 2;
        t = 0;

        for (i = 2;i <= sqrt(z); ++i) {
            if (z % i == 0) {
                q = z / i;
                a =(i + q - 1) / 2;
                b = a - i;
                ++b;
                q = (a + b) * (a - b + 1);
                if (q == z) {
                    t = 1;
                    printf("%d = ",n);
                    for (j = b;j < a; ++j)
                        printf("%d + ",j);
                    printf("%d\n",a);
                }
            }
            if (t) break;
        }
        if (t == 0) printf("IMPOSSIBLE\n");
    }
    return 0;
}
