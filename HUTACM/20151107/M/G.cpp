#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int n,a[26],i;
char c;

int main(){
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	getchar();
	for (i=0;i<n;++i){
		c=getchar();
		if (c>='a') ++a[c-'a'];
			else ++a[c-'A'];
	}

	bool t=1;
	for (i=0;i<26;++i)
		if (a[i]==0) t=0;
	if (t) printf("YES\n");
		else printf("NO\n");
	return 0;
}
