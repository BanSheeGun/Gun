#include<cstdio>
#include<cstring>
using namespace std;

const int dx[4]={0,0,0,1};
const int dy[4]={0,0,1,0};
const int kb[6][5]={{-1,-1,-1,-1,-1},
     /*keyboard*/   {-1, 1, 2, 3,-1},
                    {-1, 4, 5, 6,-1},
                    {-1, 7, 8, 9,-1},
                    {-1,-1, 0,-1,-1},
                    {-1,-1,-1,-1,-1}};
int T,n,k,i,j;
bool v[1111];

void dfs(int x,int y,int num){
//  printf("dfs(%d,%d,%d)\n",x,y,num);
    if (kb[x][y]!=0||num!=0){
        int nu=num*10+kb[x][y];
        if (nu<=400){
            v[nu]=true;
            dfs(x,y,nu);
        }
    }

    for (int i=2;i<=3;i++){
        int cx=x+dx[i];
        int cy=y+dy[i];
        if (kb[cx][cy]==-1) continue;
        dfs(cx,cy,num);
    }
}

int main(){
    dfs(1,1,0);

    v[0]=1;
    for (n=1;n<=200;++n) {
            printf("%d ",n);
        if (v[n]) printf("%d\n",n);
        else {
            k=1;
            while(n-k>=0){
                if (v[n+k]) {printf("%d\n",n+k);break;}
                if (v[n-k]) {printf("%d\n",n-k);break;}
                k++;
            }
        }
    }
    return 0;
}
