#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int a[1000000];
int a1[4]={1,1,1,1};
int a2[4]={1,2,4,3};
int a3[4]={1,3,4,2};
int a4[4]={1,4,1,4};

int main(){
	int top=0,i,ans;
	char c;

	while (~scanf("%c",&c)) {
		if (!((48<=c)&&(c<=57))) break;
		++top;
		a[top]=(int)c-48;
	}

	for (i=1;i<top;++i)
		a[i+1]=a[i+1]+10*(a[i]%4);

	i=a[top]%4;
	ans=a1[i]+a2[i]+a3[i]+a4[i];

	printf("%d\n",ans%5);

	return 0;
}
