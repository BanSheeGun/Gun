#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int a[1010];
char c;
int n,i,t1,t2,b,ans=0,t;
int main(){
	scanf("%d",&n);
	getchar();
	for (i=1;i<=n;++i){
		c=getchar();
		a[i]=(int)c-48;
	}
	getchar();
	for (i=1;i<=n;++i){
		c=getchar();
		b=(int)c-48;
		t=0;
		t1=b;t2=b;
		while (t1!=a[i]&&t2!=a[i]){
			++t;
			++t1;
			--t2;
			t1=(t1+10)%10;
			t2=(t2+10)%10;
		}
		ans+=t;
	}
	printf("%d\n",ans);
	return 0;
}
