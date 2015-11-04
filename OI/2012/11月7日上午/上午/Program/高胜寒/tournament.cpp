#include<cstdio>
#include<cstring>
int map[60][60],cnt[60],n;
bool dfs(int x,int y){
    if (x==y) return true;
    for (int i=1;i<=n;i++)
        if (map[x][i] && dfs(i,y)) return true;
    return false;
}
int main(){
    int i,a,b,x,y;
    freopen("tournament.in","r",stdin);
    freopen("tournament.out","w",stdout);
    scanf("%d",&n);
    memset(map,false,sizeof map);
    memset(cnt,0,sizeof cnt);
    for (i=1;i<n*(n-1)/2;i++){
        scanf("%d%d",&a,&b);
        map[a][b]=true;
        cnt[a]++;
        cnt[b]++;
    }
    x=y=0;
    for (i=1;i<=n;i++)
        if (cnt[i]!=n-1)
            if (x) y=i; else x=i;
    if (dfs(x,y)) printf("%d %d\n",x,y); else printf("%d %d\n",y,x);
    return 0;
}
