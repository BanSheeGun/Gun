#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
      int n,ans,l,la,a,i;
      scanf("%d",&n);
      ans=0;la=0;l=0;
      for (i=1;i<=n;++i){
            scanf("%d",&a);
            if (a>=la) ++l;
            else l=1;
            ans=max(ans,l);
            la=a;
      }
      printf("%d\n",ans);
      return 0;
}
