#include<iostream>
#include<math.h>
using namespace std;
int main(){
	double n;
	scanf("%lf",&n);
	while (n!=0){
		double r1,r2;
		r1=sqrt(n*n/3);
		r2=sqrt(n*n*2/3);
		printf("%.3lf %.3lf\n",r1,r2);
		scanf("%lf",&n);
	}
	return 0;
}
