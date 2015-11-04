/*
  Name: tournament.cpp
  Copyright: Zpc
  Author: Zpc
  Date: 23-10-11 08:41
  Description: test 1 
*/

#include <iostream>
using namespace std;

int n,m;
int f[64];
bool h[64][64];

int main()
{
	freopen("tournament.in","r",stdin);
	freopen("tournament.out","w",stdout);
	
	int i,j,k,x,y;
	scanf("%d",&n);
	m=n*(n-1)/2-1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		h[x][y]=true;
		f[x]++;
		f[y]++;
	}
	for(i=1;i<=n;i++)
		if(f[i]<n-1)
		{
			x=i;
			break;
		}
	for(i=n;i>=1;i--)
		if(f[i]<n-1)
		{
			y=i;
			break;
		}
	for(i=1;i<=n;i++)
		if(i!=x && i!=y)
			if(h[x][i] && h[i][y])
				break;
			else if(h[y][i] && h[i][x])
				swap(x,y);
	printf("%d %d\n",x,y);
	
//	system("pause");
	return 0;
}
