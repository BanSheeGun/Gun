#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	int c,z;
	scanf("%d",&c);
	for (z=1;z<=c;++z){
		int n;
		scanf("%d",&n);
		int i;
		int a[501];
		for (i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		sort(a,a+n,cmp);
		int m;
		m=a[n/2];
		int ans=0;
		for (i=0;i<n;++i){
			ans=ans+abs(a[i]-m);
		}
		printf("%d\n",ans);
	}
	return 0;
}
