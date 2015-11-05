#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

int x1,x2,x3,x4,y1,y2,y3,y4,c1,c2;
int dx1,dx2,dy1,dy2,n,i;

bool p(){
	if (c1*dx2!=c2*dx1) return 0;
	if (c1*dy2!=c2*dy1) return 0;
	return 1;
}

int main(){

	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");

	for (i=0;i<n;++i) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		scanf("%d%d%d%d",&x3,&y3,&x4,&y4);
		dx1=x1-x2;dy1=y1-y2;
		dx2=x3-x4;dy2=y3-y4;
		c1=x1*y2-x2*y1;
		c2=x3*y4-x4*y3;
		if (dx1*dy2==dx2*dy1) {
			if (p()) printf("LINE\n");
				else printf("NONE\n");
		} else {
			double t=dy2*dx1-dy1*dx2;
			double x=(double)(dx2*c1-dx1*c2)/t;
			double y=(double)(dy2*c1-dy1*c2)/t;
			printf("POINT %.2f %.2f\n",x,y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
