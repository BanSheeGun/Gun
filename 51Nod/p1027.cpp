#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )

const int MAXN = 100005 ;
const double pi = acos ( -1.0 ) ;

struct Complex {
    double r , i ;
    Complex () {}
    Complex ( double r , double i ) : r ( r ) , i ( i ) {}
    Complex operator + ( const Complex& t ) const {
        return Complex ( r + t.r , i + t.i ) ;
    }
    Complex operator - ( const Complex& t ) const {
        return Complex ( r - t.r , i - t.i ) ;
    }
    Complex operator * ( const Complex& t ) const {
        return Complex ( r * t.r - i * t.i , r * t.i + i * t.r ) ;
    }
} ;


ll la, lb, i, t, m, inv, d;
char s[400000];
Complex a[400000];
Complex b[400000];
ll ans[400000];


void FFT ( Complex y[] , int n , int rev ) {
    for ( int i = 1 , j , t , k ; i < n ; ++ i ) {
        for ( j = 0 , t = i , k = n >> 1 ; k ; k >>= 1 , t >>= 1 ) j = j << 1 | t & 1 ;
        if ( i < j ) swap ( y[i] , y[j] ) ;
    }
    for ( int s = 2 , ds = 1 ; s <= n ; ds = s , s <<= 1 ) {
        Complex wn ( cos ( rev * 2 * pi / s ) , sin ( rev * 2 * pi / s ) ) , w ( 1 , 0 ) , t ;
        for ( int k = 0 ; k < ds ; ++ k , w = w * wn ) {
            for ( int i = k ; i < n ; i += s ) {
                y[i + ds] = y[i] - ( t = w * y[i + ds] ) ;
                y[i] = y[i] + t ;
            }
        }
    }
    if ( rev == -1 ) for ( int i = 0 ; i < n ; ++ i ) y[i].r /= n ;
}

 
int main() {
    scanf("%s", s); la = strlen(s); memset(a, 0, sizeof(a));
    for (i = 0; i < la; ++i) a[i] = Complex(s[la - 1 - i] - 48, 0);
    scanf("%s", s); lb = strlen(s); memset(b, 0, sizeof(b));
    for (i = 0; i < lb; ++i) b[i] = Complex(s[lb - 1 - i] - 48, 0);;
    m = max(la, lb);
    for (d = 1; d <= m << 1; d <<= 1);
    for (i = la; i < d; ++i) a[i] = Complex(0, 0);
    for (i = lb; i < d; ++i) b[i] = Complex(0, 0);
    FFT(a, d, 1); FFT(b, d, 1);
    for (i = 0; i < d; ++i)
        a[i] = a[i] * b[i];
    FFT(a, d, -1); ans[0] = 0;
    t = 0;
    for (i = 0; i < d; ++i) {
        ans[i] = round(a[i].r);
    }
    for (i = 0; i < d; ++i) {
        ans[i+1] += ans[i] / 10; 
        ans[i] %= 10;
        if (ans[i] != 0) t = i;
    }
    for (i = t; i >= 0; --i) printf("%lld", ans[i]);
    printf("\n");
    return 0;
}