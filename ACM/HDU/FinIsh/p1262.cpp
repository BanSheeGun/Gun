#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool p[10001];
int i,j,n;
int main(){
	for (i=1;i<=10000;++i) p[i]=1;
	p[1]=0;
    for (i=2;i<=10000;++i)
    	if (p[i]==1){
    		for (j=2;j<=10000/i;++j)
    			p[i*j]=0;
    	}
    while (~scanf("%d",&n)){
    	i=n/2;j=n/2;
    	while ((p[i]==0)||(p[j]==0)){
    		--i;++j;
    	}
    	printf("%d %d\n",i,j);
    }
	return 0;
}
