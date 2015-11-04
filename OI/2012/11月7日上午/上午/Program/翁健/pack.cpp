#include <cstdio>
#include <cstdlib>
#include <cstring>
#define max(a,b) ((a)>(b)?(a):(b))
FILE *Fin= fopen("pack.in" , "r"),
	*Fout= fopen("pack.out", "w");
const int MaxN= 200010;
int N,M,v[MaxN],w[MaxN],opt[MaxN/1000+10],tot,ans;
int main(){
	fscanf(Fin,"%d%d",&N,&M);
	for(int i= 0;i< N;++ i){
		int x,A,B,C;
		fscanf(Fin,"%d",&x);
		if(x==1){
			fscanf(Fin,"%d%d",&A,&B);
			for(int i= 1;i<= M;++ i) w[tot]= i,v[tot++]= i*i*A-B*i;
		}
		if(x==2)
			for(fscanf(Fin,"%d%d%d",&A,&B,&C);C--;) v[tot]= A,w[tot++]= B;
		if(x==3){
			fscanf(Fin,"%d%d",&A,&B);
			for(int i= A,j= B;j<= M;i+= A,j+= B) v[tot]= i,w[tot++]= j;
		}
	}
	for(int i= 0;i< tot;++ i)
		for(int j= M;j>= w[i];-- j)
			opt[j]= max(opt[j],opt[j-w[i]]+v[i]);
	for(int i= 0;i<= M;++ i)
		ans= max(ans,opt[i]);
	fprintf(Fout,"%d\n",ans);
	return 0;
}
