#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;

const double PI = acos(-1.0);

struct Point
{
	int x,y;
};

Point a[1010];
int n,i,m,j;
double r,ans;
int ch[1010];


bool cmp(Point x,Point y){
	if (x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}

double Length(Point a,Point b){
	double l=(a.x-b.x)*(a.x-b.x);
	l+=(a.y-b.y)*(a.y-b.y);
	return sqrt(l);
}

int det(int a,int b,int c,int d){
	return a*d-b*c;
}

int sign(int a){
	if (a==0) return 0;
	if (a>0) return 1;
	return -1;
}

bool p(){
	if (m==1) return 0;
	int x,y,xx,yy,t;
	x=a[ch[m]].x-a[ch[m-1]].x;
	y=a[ch[m]].y-a[ch[m-1]].y;
	xx=a[i].x-a[ch[m-1]].x;
	yy=a[i].y-a[ch[m-1]].y;
	t=det(x,y,xx,yy);
	t=sign(t);
	return (t!=1);
}

int main(){
	scanf("%d%lf",&n,&r);
	for(i=1;i<=n;++i)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+1+n,cmp);

	m=2;
	ch[1]=1;ch[2]=2;
	for (i=3;i<=n;++i){
		while (p()) --m;
		++m;
		ch[m]=i;
	}
	ans=0;
	for (i=2;i<=m;++i)
		ans+=Length(a[ch[i]],a[ch[i-1]]);
	m=2;
	ch[1]=n;ch[2]=n-1;
	for (i=n-2;i>0;--i){
		while (p()) --m;
		++m;
		ch[m]=i;
	}
	for (i=2;i<=m;++i)
		ans+=Length(a[ch[i]],a[ch[i-1]]);
	ans+=PI*r*(double)2;
	printf("%.0f\n",ans);
	return 0;
}
