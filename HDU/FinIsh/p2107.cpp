#include<iostream>
using namespace std;
int main(){
	int n,i,ma,a;
	scanf("%d",&n);
	while (n!=0){
		scanf("%d",&ma);
		for (i=2;i<=n;++i){
			scanf("%d",&a);
			ma=max(ma,a);
		}
		scanf("%d",&n);
		printf("%d\n",ma);
	}
	return 0;
}