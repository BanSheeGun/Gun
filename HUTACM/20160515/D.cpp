#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

const int N = 10000000;

bool a[N+1];
int i, j, top = 0;

int main() {
    memset(a, 0, sizeof(a));
    for (i = 2; i <= N;++i) {
        if (a[i] == 0) {
            ++top;
            printf("%d ", i);
            if (top % 10 == 0)
                printf("\n");
            for (j = i + i; j <= N; j = j + i)
                a[j] = 1;
        }
    }
    return 0;
}
