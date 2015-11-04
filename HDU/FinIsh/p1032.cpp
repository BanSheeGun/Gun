#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int l,r,i,a,b,ll,rr;

int dfs(long long n){
	if (n==1) return 1;
	if (n%2==0) {
		return dfs(n/2)+1;
	}
	else {
		return dfs(3*n+1)+1;
	}
	return 0;
}

int main() {
    while (~scanf("%d%d",&l,&r)){
    	ll=min(l,r);
    	rr=max(l,r);
    	a=0;
    	for (i=ll;i<=rr;++i) {
    		b=dfs(i);
    		a=max(a,b);
    	}
    	printf("%d %d %d\n",l,r,a);
    }
	return 0;
}
