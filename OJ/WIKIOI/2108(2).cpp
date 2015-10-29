#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
double x[110],y[110];
double r=9999999;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lf %lf",&x[i],&y[i]);
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	for(int k=1;k<=n;++k)
	{
	 double u=fabs((x[i]*(y[j]-y[k])+y[i]*(x[k]-x[j])+x[j]*y[k]-y[j]*x[k])/2);
	 if(u<r && u>0.0001)r=u;
	}
    if(r<999999)printf("%.2lf",r);
    else printf("Impossible");
	return 0;
}