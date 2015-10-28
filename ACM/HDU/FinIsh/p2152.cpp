#include<iostream>
#include<memory.h>
using namespace std;
int main(){
	int n,m,i,j,k;
	int a[101];
	int b[101];
	int f[101];
	while (scanf("%d%d",&n,&m)!=EOF){
		for (i=1;i<=n;++i){
			scanf("%d%d",&a[i],&b[i]);
			m=m-a[i];
			b[i]=b[i]-a[i];
		}
		memset(f,0,sizeof(f));
		f[0]=1;
		if (m<0){printf("0\n");}
		else {
			for (j=1;j<=n;++j){
				for (k=m;k>=1;--k){
					for (i=1;i<=b[j];++i){
						if (k-i>=0){f[k]=f[k]+f[k-i];}
					}
				}
			}
			printf("%d\n",f[m]);
		}
	}
	return 0;
}
