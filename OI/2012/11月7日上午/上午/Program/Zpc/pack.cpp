/*
  Name: pack.cpp
  Copyright: Zpc
  Author: Zpc
  Date: 23-10-11 09:17
  Description: test 2 
*/

#include <iostream>
using namespace std;

struct bag
{
	int k,a,b,c;
};


int n,m;
int f[2500];
bag h[1000];

int main()
{
	freopen("pack.in","r",stdin);
	freopen("pack.out","w",stdout);
	
	int i,j,k,t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i].k);
		if(1==h[i].k || 3==h[i].k)
			scanf("%d%d",&h[i].a,&h[i].b);
		else 
			scanf("%d%d%d",&h[i].a,&h[i].b,&h[i].c);
	}
	for(i=1;i<=n;i++)
		if(2==h[i].k)
		{
			k=1;
			while(h[i].c>0)
			{
				t=min(k,h[i].c);
				for(j=m;j>=h[i].b*t;j--)
					f[j]=max(f[j],f[j-h[i].b*t]+h[i].a*t);
				h[i].c-=k;
				k*=2;
			}
		}
		else if(3==h[i].k)
		{
			for(j=h[i].b;j<=m;j++)
				f[j]=max(f[j],f[j-h[i].b]+h[i].a);
		}
		else
		{
			t=(int)(h[i].a*2.0/h[i].b+0.5);
			for(j=m;j>0;j--)
			{
				for(k=1;k<=min(t,j);k++)
					f[j]=max(f[j],f[j-k]+h[i].a*k*k-h[i].b*k);
			}
		}
	printf("%d\n",f[m]);	

//	system("pause");
	return 0;
}
