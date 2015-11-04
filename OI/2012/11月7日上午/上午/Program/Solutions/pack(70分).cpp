#include <fstream>
using namespace std;
ifstream cin("pack.in");
ofstream cout("pack.out");
struct obj{
	int a, b, c, type;
	int operator()(int x){
		switch(type){
			case 1:
				return a*x*x - b*x;
			case 2:
				if(x > b*c)return a*c;
				else return (x/b)*a;
			case 3:
				return a*(x/b);
		}
	}
}a[128];
int n, m, f[128][2005];
int main()
{
	cin>>n>>m;
	int i, j, k;
	for(i=1; i<=n; i++){
		int type;
		cin>>a[i].type>>a[i].a>>a[i].b;
		if(a[i].type == 2)cin>>a[i].c;
	}
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			for(k=0; k<=j; k++)
				f[i][j] = max(f[i][j], f[i-1][j-k] + a[i](k));
	cout<<f[n][m]<<endl;
	return 0;
}
