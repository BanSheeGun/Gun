#include<iostream>
#include<stdio.h>

using namespace std;


int main()
{
 int n,i;
 scanf("%d",&n);

 int a,b,c;
 double k;
 while (n != 0){
  a = 0; b = 0; c = 0;
  for (i=1;i<=n;++i) {
   scanf("%lf",&k);
   if (k==0)  ++b;
   if (k>0)  ++a;
   if (k<0)  ++c;
  }

  printf("%d %d %d\n",c,b,a);
  scanf("%d",&n);
 }
 return 0;
}
