#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;


bool pan(long long n){
	while (n%5==0) {n=n/5;}
	while (n%3==0) {n=n/3;}
	while (n%2==0) {n=n/2;}
	return (n==1);
}

long long top,now;
int main() {
//	memset(a,0,sizeof(a));
//	a[1]=1;
	top=1500;now=859963392;
	while (top<1500) {
		++now;
		if (pan(now)) {
			++top;
//			a[now*2]=1;
//			a[now*3]=1;
//			a[now*5]=1;
if (top%50==0) printf("%lld %lld\n",top,now);
		}
	}
	printf("The 1500'th ugly number is %d.\n",now);
	return 0;
}
