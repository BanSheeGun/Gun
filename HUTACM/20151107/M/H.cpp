#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int t,n,m;

int f(int a){
	if (a==0) return 1;
	if (a==1) return n%10;
	int t=f(a/2)%10;
	t=t*t%10;
	if (a%2==1) t=t*n%10;
	return t%10;
}

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		m=n;
		n=n%10;
		printf("%d\n",f(m));
	}
	return 0;
}
