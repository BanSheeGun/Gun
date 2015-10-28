#include<cstdio>
#include<cstring>
using namespace std;
bool p(int y){
   if(y%4==0&&y%100!=0||y%400==0) return 1;
   return 0;
}
int p2(int m,int d){
	if (m==1) return 1;
	if (m==2&&d<29) return 1;
	if (m==2&&d==29) return 2;
	return 0;
}
int main(){
	int tt,i,t,y,m,d,ans;
	scanf("%d",&t);
	for (tt=1;tt<=t;++tt){
		scanf("%d-%d-%d",&y,&m,&d);
		ans=0;
		for (i=1;i<=18;++i){
		    if (p(y)&&p2(m,d)>=1) ++ans;
			++y;
			if (p(y)&&p2(m,d)==0) ++ans;
		}
	    ans+=6570;
	    if (!p(y)&&p2(m,d)==2) printf("-1\n");
	    else printf("%d\n",ans);
	}
	return 0;
}
