/**************************************************************
    Problem: 1441
    User: Gunpowder
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:820 kb
****************************************************************/
 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
inline int read() {
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
int ans, n;
 
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}
 
int main() {
    ans = 0;
    n = read();
    while (n--) {
        ans = gcd(abs(read()), ans);
    }    
    printf("%d\n", ans);
    return 0;
}