#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

bool cmp(int a,int b){
	return a<b;
}
int a[3001],n,m,i,mm;

int main(){
	while (~scanf("%d%d",&n,&m)){
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(i=1;i<=m;++i)
			scanf("%d",&a[i+n]);
		mm=a[1];
		for (i=2;i<=m+n;++i)
			mm=max(mm,a[i]);
		sort(a+1,a+1+n+m,cmp);
		a[0]=a[1]-1;
		for (i=1;i<=m+n;++i)
			if (a[i]!=a[i-1]){
				printf("%d",a[i]);
				if (a[i]!=mm) printf(" ");
			}
		printf("\n");
	}
	return 0;
}
