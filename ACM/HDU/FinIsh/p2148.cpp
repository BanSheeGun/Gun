#include<iostream>
int main(){
	int t,tt,n,i,s,ss;
	int f[1001];
	scanf("%d",&t);
	for (tt=0;tt<t;++tt){
		scanf("%d%d",&n,&s);
		for (i=1;i<=n;++i){
			scanf("%d",&f[i]);
		}
		s=f[s];ss=0;
		for (i=1;i<=n;++i){
		    if (s<f[i]){++ss;}	
		}
		printf("%d\n",ss);
	}
	return 0;
}
