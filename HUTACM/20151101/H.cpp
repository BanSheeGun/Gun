#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct pc
{
	int x,y;
};
pc a[10000000];

int main(){
    int n,i,j;
    scanf("%d",&n);
    bool ans=0;
    for (i=0;i<n;++i) {
    	scanf("%d%d",&a[i].x,&a[i].y);
        if (a[i].x!=a[i].y) ans=1;
    }
    if (ans) printf("Happy Alex\n");
    else printf("Poor Alex\n");
	return 0;
}
