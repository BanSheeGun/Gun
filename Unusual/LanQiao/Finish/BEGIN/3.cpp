#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

double r, s;
double PI = atan(1.0) * 4;
int main() {
    scanf("%lf",&r);
    s = PI* r * r;
    printf("%.7lf\n",s);
    return 0;
}
