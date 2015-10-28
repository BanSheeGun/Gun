#include<iostream>
using namespace std;
int main(){
	int n,q,w,e,r,qq,ww,ee,rr,ans;
	while (scanf("%d",&n) != EOF){
		ans=0;
		for (q=0;q<=n/50;++q){
			qq=n-q*50;
			for (w=0;w<=qq/25;++w){
				ww=qq-w*25;
				for (e=0;e<=ww/10;++e){
					ee=ww-e*10;
					for (r=0;r<=ee/5;++r){
						rr=ee-r*5;
						if (q+w+e+r+rr<=100){
							ans=ans+1;
						}
					}
				}
			}
		}
        printf("%d\n",ans);
	}
	return 0;
}
