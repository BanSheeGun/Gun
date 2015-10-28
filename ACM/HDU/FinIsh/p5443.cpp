#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int ls[40001];
int rs[800001];
int ans[800001];
int s[300001];
void creat(int now,int l,int r){
    ls[now]=l;rs[now]=r;
	if (l==r) {
		ans[now]=s[l];
		return;
	}
	int mid=(l+r)/2;
	creat(now*2,l,mid);
	creat(now*2+1,mid+1,r);
	ans[now]=max(ans[now*2],ans[now*2+1]);
	return;
}
int find(int now,int l,int r){
	int a,b;
	if ((l<=ls[now])&&(rs[now]<=r)) {
		return ans[now]; 
	}
	a=0;
	int mid=(ls[now]+rs[now])/2;
	if (l<=mid) {
		a=find(now*2,l,r);
		if (mid<r) {
			b=find(now*2+1,l,r);
		    a=max(a,b);
		}
	} else{
		if (mid<r) {
			a=find(now*2+1,l,r);
		}
	}
	return a;
}
int main(){
	char ch[10];
	int n,m,i,l,r,a,t,tt;
	scanf("%d",&t);
    for(tt=1;tt<=t;++tt){
    	scanf("%d",&n);
		for (i=1;i<=n;++i){
			scanf("%d",&s[i]);
		}
		creat(1,1,n);	
		scanf("%d",&m);
		for (i=1;i<=m;++i){
			scanf("%d%d",&l,&r);
			int a=find(1,l,r);
			printf("%d\n",a);
		}
    }
	return 0;
}
