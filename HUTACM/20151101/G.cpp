#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int x1,x2,x3,x4;
	int y1,y2,y3,y4,d;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);


	bool ans=1;

	if ((x1==x2)||(y1==y2)) {
		if (x1==x2) {
			d=abs(y1-y2);
			x3=x1+d;
			x4=x2+d;
			y3=y1;
			y4=y2;
		} else {
			d=abs(x1-x2);
			x3=x1;
			x4=x2;
			y3=y1+d;
			y4=y2+d;
		}
	} else {
		int d1=x1-x2;
		int d2=y1-y2;
		if ((d1+d2==0)||(d1-d2==0)) {
			x3=x1;
			y3=y2;
			x4=x2;
			y4=y1;
		} else ans=0;
	}

	if (ans==0) printf("%d\n",-1);
	else printf("%d %d %d %d\n",x3,y3,x4,y4);
	return 0;
}
