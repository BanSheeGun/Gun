#include<iostream>
using namespace std;
int main(){
	int c,z;
	scanf("%d",&c);
	for (z=1;z<=c;++z){
		int n,i;
		scanf("%d",&n);
		double m,a;
		scanf("%lf",&m);
		for (i=2;i<=n;++i){
			scanf("%lf",&a);
			if (a>m) {m=a;}
		}
		printf("%.2lf\n",m);
	}
	return 0;
}
