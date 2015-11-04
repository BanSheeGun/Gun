#include<iostream>
#include<memory.h>
using namespace std;
int main(){
	int a,b,i,top;
	scanf("%d%d",&a,&b);
	bool p[100];
	while (!((a==0)&&(b==0))){
		memset(p,0,sizeof(p));
		top=0;
		for (i=0;i<=99;++i){
			if ((a*100+i)%b ==0){
				p[i]=1;
				top=top+1;
			}
        }
		for (i=0;i<=99;++i){
			if (p[i]==1){
				if (top==1){
					printf("%d%d",i/10,i%10);
				} else {
					printf("%d%d ",i/10,i%10);
					top=top-1;
				}
			}
		}
		printf("\n");
	    scanf("%d%d",&a,&b);
	}
}
