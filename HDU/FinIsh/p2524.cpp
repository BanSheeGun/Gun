#include<iostream>
using namespace std;
int main(){
	int i,j,n,m,k,z;
	long long ans;
	scanf("%d",&m);
	for (k = 0; k < m; ++k){
		scanf("%d%d",&n,&z);
		ans=0;
		for(i=1;i<=n;++i){
			for (j=1;j<=z;++j){
				ans+=(n+1-i)*(z+1-j);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
