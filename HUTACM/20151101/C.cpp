#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int n,m,a,b,ans=0,i;
	bool t=0;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i){
		scanf("%d%d",&a,&b);
		if (a<m) {
			t=1;
			if (b!=0) ans=max(ans,100-b);
		} else {
			if (a==m&&b==0) t=1;
		}
	}
	if (t==0) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
