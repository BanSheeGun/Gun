#include<cstring>
#include<cstdio>

using namespace std;

int main(){
	int n,m,ans;
	scanf("%d%d",&n,&m);

	ans=0;
	while (n>0){
		++ans;
		--n;
		if (ans!=1 && ans%m==0) ++n;
	}
	printf("%d\n",ans);
	return 0;
}
