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
int n,i,m,j,ans;
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
	n=0;
	while (~scanf("%d%d",&a[n+1].x,&a[n+1].y)){
		++n;
	}
	sort(a+1,a+1+n,cmp);

	m=2;
	ch[1]=1;ch[2]=2;
	for (i=3;i<=n;++i){
		while (p()) --m;
		++m;
		ch[m]=i;
	}
	ch[m]=n;ch[m+1]=n-1;
	m+=1;
	for (i=n-2;i>0;--i){
		while (p()) --m;
		++m;
		ch[m]=i;
	}
	--m;
	for(i=1;i<=m;i++)
		if (a[ch[i]].x==0&&a[ch[i]].y==0) {
			ans=i;
			break;
		}
	for(i=1;i<=m;i++) {
		printf("(%d,%d)\n",a[ch[ans]].x,a[ch[ans]].y);
		ans%=m;
		++ans;
	}
	return 0;
}
