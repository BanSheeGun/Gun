#include <bits/stdc++.h>
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
using namespace std;

int main() {
    freopen("ou.txt","w",stdout);
    int n = 141, m = 762, l = 31;
    printf("%d %d\n",n,m);
    int cnt=0;
    lpi(i,1,30)for(int j=1;j<=30/i;j++,l++)lp(k,0,i) //cnt++;
        printf("puts(%d %d)\n",i*j+k-i+1,l);
    //printf("%d\n",cnt);

    printf("%d\n",30);
    lpi(i,1,30)printf("puts(%d)\n", i);
    return 0;
}
