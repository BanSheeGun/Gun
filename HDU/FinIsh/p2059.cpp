#include<iostream>
#include<memory.h>
using namespace std;
int n,c,t,i,vr,v1,v2,j;
double w(int a,int b){
	double ans;
	if (b-a>=c){
		ans=double(c)/v1;
		ans=ans+double(b-a-c)/v2;
	}else{
		ans=double(b-a)/v1;
	}
	return ans;
}
int main(){
	double l;
	while (scanf("%lf",&l)!=EOF){
		scanf("%d%d%d",&n,&c,&t);
		scanf("%d%d%d",&vr,&v1,&v2);
		int a[101];
		for (i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		n=n+1;
		a[n]=l;
		double f[101];
		memset(f,0,sizeof(f));
		for (i=1;i<=n;++i){
			f[i]=w(0,a[i])+t;
			for (j=1;j<i;++j){
				f[i]=min(f[i],f[j]+w(a[j],a[i])+t);
			}
		}
		if (f[n]-t<l/vr) {
			printf("What a pity rabbit!\n");
		}
		else {
			printf("Good job,rabbit!\n");
		}
	}
	return 0;
}

