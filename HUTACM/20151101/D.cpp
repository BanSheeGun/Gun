#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int n,i,m,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;++i){
		scanf("%d",&k);
		m=max(k,m);
	}
	printf("%d\n",m);
	return 0;
}
