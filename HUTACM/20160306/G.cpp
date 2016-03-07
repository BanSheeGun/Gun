#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

int prime[400];
int a[20];
bool t[20];
int n, test;

int InitPrime() {
    int i , j;
    memset(prime, 0, sizeof(prime));
    for (i = 2; i < 400; ++i)
        if (prime[i] == 0) {
            for (j = 2;j * i < 400; ++j)
                prime[i * j] = 1;
        }
    return 0;
}

int dfs(int k) {
    for (int i = 2;i <= n; ++i)
        if (t[i] == 0 && prime[i + a[k-1]] == 0) {
            a[k] = i;
            if (n == k) {
                if (prime[i + 1] == 0) {
                    for (int j = 1;j < n; ++j)
                        printf("%d ",a[j]);
                    printf("%d\n",a[n]);
                }
            } else {
                t[i] = 1;
                dfs(k + 1);
                t[i] = 0;
            }
        }
    return 0;
}

int main() {
    InitPrime();
    test = 0;
    while (~scanf("%d",&n)) {
        test++;
        printf("Case %d:\n",test);
        a[1] = 1;
        memset(t, 0, sizeof(t));
        t[1] = 1;
        dfs(2);
        printf("\n");
    }
    return 0;
}
