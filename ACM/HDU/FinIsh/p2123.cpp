#include<iostream>
using namespace std;
int main(){
	int n,i,j,t,tt;
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt){
		scanf("%d",&n);
		for (i=1;i<=n;++i){
			for (j=1;j<n;++j){
				printf("%d ",i*j);
			}
			printf("%d\n",i*n);
		}
	}
	return 0;
}
