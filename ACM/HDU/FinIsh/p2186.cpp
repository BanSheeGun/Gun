#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n,i,a,b,c,ans;
	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d",&ans);
		a=ans/2;
		ans=ans-a;
		b=ans*2/3;
		c=ans-b;
		ans=ceil((double)a/10);
		ans+=ceil((double)b/10);
		ans+=ceil((double)c/10);
		printf("%d\n",ans);
	}
	return 0;
}
