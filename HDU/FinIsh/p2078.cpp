#include<iostream>
#include<algorithm>
#include<math.h>
#include<memory.h>

using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int t,tt;
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt){
		int a[41];
		int f[41];
		memset(f,0,sizeof(f));
		int n,m,i;
		scanf("%d%d",&n,&m);
		for (i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+n,cmp);
        int j,k,s;
		for (j=1;j<=m;++j){
			for (i=0;i<n;++i){
				for (k=i+1;k<n;++k){
					f[i]=max(f[i],f[k]+(int)pow(a[i]-a[k],2));
				}
			}
		}
		for (i=0;i<n;++i){
			f[i]=f[i]+(int)pow(100-a[i],2);
		}
		s=f[0];
		for (i=0;i<n;++i){
			s=max(s,f[i]);
		}
		printf("%d\n",s);
	}
	return 0;
}
