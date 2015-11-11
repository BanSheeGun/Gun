#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char c;
int a[1010][1010];
bool t[1010][1010];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int d[40000][3];
int n,m,i,j,f,p,a1,a2,a3,x,y,xx,yy;
int main(){
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;++i){
		getchar();
		for (j=1;j<=m;++j){
			scanf("%c",&c);
			switch(c){
				case '1':a[i][j]=1;break;
				case '2':a[i][j]=2;break;
				case '3':a[i][j]=3;break;
				case '.':a[i][j]=0;break;
				case '#':a[i][j]=-1;break;
				default:break;
			}
		}
	}	
	for (i=0;i<=n+1;++i){
		a[i][0]=-1;
		a[i][m+1]=-1;
	}
	for (i=0;i<=m+1;++i){
		a[0][i]=-1;
		a[n+1][i]=-1;
	}
	
	f=1;p=0;
	memset(t,0,sizeof(t));
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
			if (a[i][j]==1) {
				++p;
				d[p][0]=i;
				d[p][1]=j;
				t[i][j]=1;
				d[p][2]=0;
			}
	
	a1=-1;a2=-1;
	do{
		x=d[f][0];
		y=d[f][1];
		for (i=0;i<4;++i){
			xx=x+dx[i];
			yy=y+dy[i];
			if (a[xx][yy]>-1&&t[xx][yy]==0){
				++p;
				d[p][0]=xx;
				d[p][1]=yy;
				d[p][2]=d[f][2]+1;
				t[xx][yy]=1;
				if (a[xx][yy]==2&&a1==-1){
					a1=d[p][2];
				}
				if (a[xx][yy]==3&&a2==-1){
					a2=d[p][2];
				}
			}
		}
		if (a1!=-1&&a2!=-1) break;
		++f;
	}while(f<=p);
	
	
	f=1;p=0;
	memset(t,0,sizeof(t));
	for (i=1;i<=n;++i)
		for (j=1;j<=m;++j)
			if (a[i][j]==2) {
				++p;
				d[p][0]=i;
				d[p][1]=j;
				t[i][j]=1;
				d[p][2]=0;
			}
	
	a3=-1;
	do{
		x=d[f][0];
		y=d[f][1];
		for (i=0;i<4;++i){
			xx=x+dx[i];
			yy=y+dy[i];
			if (a[xx][yy]>-1&&t[xx][yy]==0){
				++p;
				d[p][0]=xx;
				d[p][1]=yy;
				d[p][2]=d[f][2]+1;
				t[xx][yy]=1;
				if (a[xx][yy]==3&&a3==-1){
					a3=d[p][2];
				}
			}
		}
		if (a3!=-1) break;
		++f;
	}while(f<=p);
	
	
	
	
	if (a2<a1) swap(a1,a2);
	if (a3<a1) swap(a3,a1);
	if (a3<a2) swap(a3,a2);
	c=0;
	if (a1==-1) ++c;
	if (a2==-1) ++c;
	if (a3==-1) ++c;
	if (c>1) printf("-1\n");
		else if (c==1) printf("%d\n",a2+a3-2);
			else printf("%d\n",a1+a2-2);
	return 0;
}