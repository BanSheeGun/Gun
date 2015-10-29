#include <cstdio>
#include <cstdlib>
#include <cstring>
#define _TYPE [MaxN][MaxN]
FILE *Fin= fopen("tournament.in" , "r"),
	*Fout= fopen("tournament.out", "w");
const int MaxN= 55;
int N;
bool gra _TYPE,g _TYPE;
int main(){
	fscanf(Fin,"%d",&N);
	for(int j= 0;j< N*(N-1)/2;++ j){
		int a,b;
		fscanf(Fin,"%d%d",&a,&b);
		gra[a][b]= 1;
		g[a][b]= 1;
	}
	for(int k= 1;k<= N;++ k)
		for(int i= 1;i<= N;++ i)
			for(int j= 1;j<= N;++ j)
				g[i][j]|= g[i][k] && g[k][j];
	for(int i= 1;i<= N;++ i)
		for(int j= 1;j<= N;++ j)
			if(g[i][j] && !gra[i][j]){
				fprintf(Fout,"%d %d\n",i,j);
				break;
			}
	return 0;
}
