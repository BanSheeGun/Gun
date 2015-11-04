#include<iostream>
using namespace std;
int main(){
	int n,i,a,sum,j;
	scanf("%d",&n);
	j=0;
	while (n>0){
		++j;
		sum=0;
		for(i=1;i<=n;++i){
			scanf("%d",&a);
			sum+=a;
		}
		printf("Sum of #%d is %d\n",j,sum);
      	scanf("%d",&n);
	}
	return 0;
}
