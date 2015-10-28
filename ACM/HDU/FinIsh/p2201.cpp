#include<iostream>
using namespace std;
int main(){
	double a,b;
	while (scanf("%lf%lf",&a,&b)!=EOF){
		printf("%.2lf\n",(double)1/a);
	}
	return 0;
}
