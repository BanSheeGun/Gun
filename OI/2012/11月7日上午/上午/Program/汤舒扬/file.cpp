#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include<cfloat>
#include<cmath>
#include<fstream>
#include<climits>
#include<functional>
#include<utility>
using namespace std;
#include<map>

#define MAXN 1111
#define Endl endl
#define forr(I,A,B) for(int I=A;I<=B;++I)
typedef long long lld;
typedef int arr[MAXN];

ifstream fin ("file.in") ;
ofstream fout("file.out");

int n;
vector<string> rt;
map< string, vector<string> > chd;

int main()
{
	fin >>n;
	string st,ls,tmp;
	for(int i=1;i<=n;++i) {
		fin >>st;
		int pos=0,lp=0;
		bool f;
		ls="";
		while( pos < st.size() ) {
			if( st[pos] == '/' ) {
				tmp = st.substr(lp,pos-lp) + " " +ls ;
				lp = pos+1 ;
				f=true;
				for(int i=0;i<chd[ls].size();++i)
					if( chd[ls][i] == tmp ) {
						f=false;
						break;
					}
				if(f) {
					chd[ls].push_back(tmp);
					//cout <<ls <<' ' <<tmp <<endl;
				}
				ls = tmp ;
			}
			pos++;
		}
		tmp = st.substr(lp,st.size()-lp+1) +" " +ls ;
		f=true;
		for(int i=0;i<chd[ls].size();++i)  
			if( chd[ls][i] == tmp ) {
				f=false;
				break;
			}
		if(f) {
			chd[ls].push_back(tmp);
			//cout <<ls <<' ' <<tmp <<endl;
		}
	}
	void sch(const string &,int);
	sch("",-1);
	return 0;
}

void sch(const string &ss,int step) {
	//cout <<ss <<endl;
	//system("pause");
	sort( chd[ss].begin(), chd[ss].end() ) ;
	for(int i=1;i<step;++i)
		fout <<"|    " ;
	if(step>0)
		fout <<"|----" ;
	if( ss.size() ) {
		for(int i=0;i<ss.size();++i)
			if( ss[i] != ' ' )
				fout <<ss[i] ;
			else
				break;
		fout <<endl;
	}
	for( int i=0, tmp=chd[ss].size(); i<tmp; ++i )
		sch( chd[ss][i], step+1 );
}
