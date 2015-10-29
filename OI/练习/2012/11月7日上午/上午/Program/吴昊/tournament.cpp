#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,a,b,f[55][55],g[55][55];
int main()
{
	freopen("tournament.in","r",stdin);
	freopen("tournament.out","w",stdout);
	scanf("%d",&n);
	int p=n*(n-1)/2-1;
	for (int i=1;i<=p;i++)
	{
		scanf("%d%d",&a,&b);
		f[a][b]=1;
		g[a][b]=1;
	}
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (g[i][k] && g[k][j]) g[i][j]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (g[i][j] && !f[i][j]) {printf("%d %d\n",i,j);break;}
}
