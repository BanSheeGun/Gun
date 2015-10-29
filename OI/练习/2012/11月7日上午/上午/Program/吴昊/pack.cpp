#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[111],b[111],c[111],f[111][2011],x[111];
int main()
{
	freopen("pack.in","r",stdin);
	freopen("pack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		scanf("%d%d",&a[i],&b[i]);
		if (x[i]==2) scanf("%d",&c[i]);
	}
	memset(f,0,sizeof f);
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++)
		{
			f[i][j]=f[i-1][j];
			if (x[i]==1)
				for (int k=0;k<=m;k++)
					if (j>=k)
					f[i][j]=max(f[i][j],f[i-1][j-k]+a[i]*k*k-b[i]*k);
			if (x[i]==2)
			{
				int p=min(j/b[i],c[i]);
				for (int k=1;k<=p;k++)
					f[i][j]=max(f[i][j],f[i-1][j-k*b[i]]+a[i]*k);
			}
			if (x[i]==3)
			{
				int p=j/b[i];
				for (int k=1;k<=p;k++)
					f[i][j]=max(f[i][j],f[i-1][j-k*b[i]]+a[i]*k);
			}
		}
	printf("%d\n",f[n][m]);
}
