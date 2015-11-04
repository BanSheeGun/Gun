#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int n,i,j,m;
	char a[102][102];

	scanf("%d",&n);
	getchar();
	bool ans=1;

	for (i=1;i<=n;++i){
		for (j=1;j<=n;++j) {
			a[i][j]=getchar();
		}
		getchar();
	}
	for (i=0;i<=n+1;++i){
		a[0][i]='~';
		a[n+1][i]='~';
		a[i][0]='~';
		a[i][n+1]='~';
	}

	for (i=1;i<=n;++i)
		for (j=1;j<=n;++j) {
			m=0;
			if (a[i+1][j]=='o') ++m;
			if (a[i][j+1]=='o') ++m;
			if (a[i-1][j]=='o') ++m;
			if (a[i][j-1]=='o') ++m;
			if (m%2==1) ans=0;
			if (ans==0) break;
		}
	if (ans==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
