#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<cassert>
#include<sstream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

#define LET(x,a)        __typeof(a) x(a)
#define IFOR(i,a,b)     for(LET(i,a);i!=(b);++i)
#define EACH(it,v)      IFOR(it,v.begin(),v.end())
#define FOR(i,a,b)      for(int i=(int)(a) ; i < (int)(b);++i)
#define REP(i,n)        FOR(i,0,n)
#define PB              push_back
#define MP              make_pair
#define EPS             1e-9
#define INF 2000000000

typedef vector<int>     VI;
typedef long long       LL;
typedef pair<int,int>   PI;

int main(){
        freopen("tournament.in","r",stdin);
        freopen("tournament.out","w",stdout);
        int n;cin>>n;
        int visited[n+2][n+2];
        memset(visited,-1,sizeof(visited));
        int num = (n*(n-1))/2 - 1;
        REP(i,num){
                int a,b;
                scanf("%d%d",&a,&b);
                visited[a][b] = 1;
                visited[b][a] = 0;
        }
        int np1,np2;
        FOR(i,1,n+1)FOR(j,1,n+1)if(i!=j){
                if(visited[i][j]==-1){
                        np1 = i;
                        np2 = j;
                }
        }
        int ans = -1;
        FOR(i,1,n+1)if(i!=np1 && i!=np2){
                if(visited[np1][i]!=visited[np2][i]){
                        if(visited[np1][i]==1)ans = 1;
                        else ans = 2;
                }
        }
        if(ans==1)cout<<np1<<" "<<np2<<endl;
        else cout<<np2<<" "<<np1<<endl;
        return 0;
}
