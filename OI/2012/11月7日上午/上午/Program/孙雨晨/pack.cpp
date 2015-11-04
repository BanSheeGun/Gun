//pack pro2-test20111023 Syc 20111023
#include <iostream>
using namespace std;

int f[2001],v[5001],w[5001],p;

int main()
{
	freopen("pack.in","r",stdin);
	freopen("pack.out","w",stdout);
	int n,m,i,j,a,b,c,x;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x==1)
			scanf("%d%d",&a,&b);
		if (x==2)
		{
			scanf("%d%d%d",&a,&b,&c);
			for (j=1;j<=c;j++)
			{
				v[++p]=a;
				w[p]=b;
			}
		}
		if (x==3)
		{
			p++;
			scanf("%d%d",&v[p],&w[p]);
		}
	}
	for (i=1;i<=p;i++)
		for (j=m;j>=w[i];j--)
			f[j]=max(f[j],f[j-w[i]]+v[i]);
	cout<<f[m]<<endl;
//	system("pause");
	return 0;
}
