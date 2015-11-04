#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cfloat>
#include<cmath>
#include<climits>
#include<functional>
#include<utility>
using namespace std;

#define MAXN 555

#define Endl endl
#define forr(I,A,B) for(int I=A;I<=B;++I)
typedef long long lld;
typedef int arr[MAXN];

ifstream fin ("tournament.in" );
ofstream fout("tournament.out");

arr d,stk,ind;
bool g[MAXN][MAXN];
int n,a,b;

bool tpst() {
	int top = 0 ;
	forr(i,1,n)
		if( ! ind[i] )
			stk[++top] = i ;
	int ct=0,tp;
	while( top >0 ) {
		tp = stk[top--] ;
		++ct;
		for(int i=1;i<=n;++i)
			if( g[tp][i] && (--ind[i])==0 )
				stk[++top] = i ;
	}
	return ct==n ;
}

int main()
{
	fin >>n;
	for(int i=1;i<n*(n-1)/2;++i) {
		fin >>a >>b;
		g[a][b]=true;
		d[a]++, d[b]++;
		ind[b]++;
	}
	a=b=0;
	for(int i=1;i<=n;++i) {
		if( d[i] == n-2 )
			if(a==0)
				a = i ;
			else
				b = i ;
	}
	g[a][b]=true;
	ind[b]++;
	if( tpst() )
		fout <<a <<' ' <<b <<endl;
	else
		fout <<b <<' ' <<a <<endl;
	return 0;
}
