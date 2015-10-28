#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	long long a,b,aa,bb;
	while (n != -1) {
        a = 1;b = 0;
        for (i=1;i<=n;i++) {
        	aa=a*3+b*2;
            bb=a+b;
            a=aa;
            b=bb;
        }
        printf("%lld, %lld\n",a,b);
	    scanf("%d",&n);
	}

	return 0;
}