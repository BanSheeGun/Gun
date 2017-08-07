#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;

int T, m;
double k;

int main() {
    T = 0;
    while (~scanf("%lf", &k)) {
        m = floor(k * log(2) / log (10));
        printf("Case #%d: %d\n", ++T, m);
    }   
    return 0;
}