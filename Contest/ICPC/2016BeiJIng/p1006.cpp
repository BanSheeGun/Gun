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
const ll M = 1ll << 10;

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


inline ll solve(double x) {
    return (ll)(round(x) + 1e-10);
}

ll la, lb, i, t, m, inv, dd, k, n, ans1, sum;
char s[400000];
Complex a[400000];
Complex b[400000];
Complex c[400000];
Complex d[400000];
Complex a1[400000];
Complex a2[400000];
Complex a3[400000];
Complex a4[400000];
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
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        la = n; lb = n; m = n;
        sum = 0;
        for (i = 0; i < la; ++i) { scanf("%lld", &k);sum = sum + k * k; 
            a[i] = Complex(k % M, 0); c[i] = Complex(k / M, 0); }
        for (i = 0; i < la; ++i) {a[i+n] = a[i]; c[i+n] = c[i];}
        la = 2 * la - 1; m = la;
        for (i = 0; i < lb; ++i) { scanf("%lld", &k);sum = sum + k * k;
            b[lb-i-1] = Complex(k % M, 0); d[lb-i-1] = Complex(k / M, 0); }
        for (dd = 1; dd <= m << 1; dd <<= 1);
        for (i = la; i < dd; ++i) a[i] = Complex(0, 0);
        for (i = lb; i < dd; ++i) b[i] = Complex(0, 0);
        for (i = la; i < dd; ++i) c[i] = Complex(0, 0);
        for (i = lb; i < dd; ++i) d[i] = Complex(0, 0);
        FFT(a, dd, 1); FFT(b, dd, 1);FFT(c, dd, 1); FFT(d, dd, 1);
        for (i = 0; i < dd; ++i)
            a1[i] = a[i] * b[i];
        for (i = 0; i < dd; ++i)
            a4[i] = c[i] * d[i];
        for (i = 0; i < dd; ++i)
            a2[i] = a[i] * d[i];
        for (i = 0; i < dd; ++i)
            a3[i] = b[i] * c[i];
        FFT(a1, dd, -1);FFT(a2, dd, -1);FFT(a3, dd, -1);FFT(a4, dd, -1);
        for (i = 0; i < dd; ++i) {
            ans[i] = solve(a1[i].r) + M * solve(a2[i].r) + M * solve(a3[i].r) + M * M * solve(a4[i].r);
        }
        ans1 = ans[n-1];
        for (i = n-1; i <= 2*n-2; ++i)
            ans1 = max(ans1, ans[i]);
        sum = sum - ans1 - ans1;
        printf("%lld\n", sum);
    }
    return 0;
}