#include<iostream>
#include<memory.h>
using namespace std;
int main(){
	int c,cc,n,i,j;
    scanf("%d",&c);
    int a[101][101];
    memset(a,0,sizeof(a));
    for (cc=1;cc<=c;cc++){
    	scanf("%d",&n);
        for (i=1;i<=n;i++){
        	for (j=1;j<=i;j++){
        		scanf("%d",&a[i][j]);
        	}
        }

        for (i=n-1;i>=1;--i){
        	for (j=1;j<=i;++j){
        		a[i][j]=a[i][j]+max(a[i+1][j],a[i+1][j+1]);
        	}
        }
        printf("%d\n",a[1][1]);
    }
	return 0;
}
