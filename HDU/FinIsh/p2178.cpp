#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n,i,j,m,ans;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&m);
		ans=(int)pow(2,m);
		printf("%d\n",ans-1);
	}
	return 0;
}
