//tournament pro1-test20111023 Syc 20111023
#include <iostream>
using namespace std;

bool flag;
int g[51][51],v[51],n,y;

void dfs(int p)
{
	if (p==y)
	{
		flag=true;
		return;
	}
	for (int i=1;i<=n;i++)
		if (v[i]&&g[p][i])
		{
			v[i]=0;
			dfs(i);
			if (flag)
				return;
			v[i]=1;
		}
}

int main()
{
	freopen("tournament.in","r",stdin);
	freopen("tournament.out","w",stdout);
	int i,j,x;
	cin>>n;
	for (i=1;i<=(n-1)*n/2-1;i++)
	{
		scanf("%d%d",&x,&y);
		g[x][y]=1;
		v[x]++;
		v[y]++;
	}
	for (i=1;i<=n;i++)
		if (v[i]<(n-1))
		{
			x=i;
			break;
		}
	for (j=i+1;j<=n;j++)
		if (v[j]<(n-1))
		{
			y=j;
			break;
		}
	for (i=1;i<=n;i++)
		v[i]=1;
	v[x]=0;
	dfs(x);
	if (flag)
		printf("%d %d\n",x,y);
	else
		printf("%d %d\n",y,x);
	return 0;
}
