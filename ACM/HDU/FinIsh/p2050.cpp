#include<iostream>
using namespace std;

int main(){
    int i,n,a;
    scanf("%d",&n);
    for (i=1;i<=n;i++){
    	scanf("%d",&a);
    	printf("%d\n",a*a*2-a+1);
    }
	return 0;
}
