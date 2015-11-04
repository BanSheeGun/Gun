#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

FILE *fin =fopen("pack.in" ,"r") ;
FILE *fout=fopen("pack.out","w") ;

#define w first
#define v second

int n,m,opt[55555],ty[55555];
vector< pair<int,int> > g[55555];

int main()
{
	fscanf(fin,"%d%d",&n,&m);
	int a,b,c;
	for(int i=1;i<=n;++i) {
		fscanf(fin,"%d",&ty[i]);
		if(ty[i]==1) {
			fscanf(fin,"%d%d",&a,&b);
			for(int j=b/a;j<=m;++j)
				g[i].push_back( make_pair( j, a*j*j-b*j ) ) ;
		}
		if(ty[i]==2) {
			fscanf(fin,"%d%d%d",&a,&b,&c);
			int tmp=1;
			while( tmp <= c ) {
				g[i].push_back( make_pair(tmp*b,tmp*a) ) ;
				c -= tmp ;
				tmp <<= 1 ;
			}
			if(c)
				g[i].push_back( make_pair(c*b,c*a) ) ;
		}
		if(ty[i]==3) {
			fscanf(fin,"%d%d",&a,&b);
			c=m;
			int tmp=1;
			while( tmp <= c ) {
				g[i].push_back( make_pair(tmp*b,tmp*a) ) ;
				c -= tmp ;
				tmp <<= 1 ;
			}
			if(c)
				g[i].push_back( make_pair(c*b,c*a) ) ;
		}
	}
	for(int i=1;i<=n;++i)
		if(ty[i]==1) {
			for(int j=m;j>=0;--j)
				for(int k=0;k<g[i].size();++k)
					if( j >= g[i][k].w )
					  opt[j] = max( opt[ j -g[i][k].w ] + g[i][k].v , opt[j] ) ;
		}
		else
			for(int k=0;k<g[i].size();++k)
				for(int j=m;j>=0;--j)
					if( j >= g[i][k].w )
					  opt[j] = max( opt[ j -g[i][k].w ] + g[i][k].v , opt[j] ) ;
	//system("pause");
	fprintf( fout, "%d\n", *max_element(opt,opt+m+1) ) ;
	return 0;
}
