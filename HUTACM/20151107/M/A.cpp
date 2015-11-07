#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;

char k,h1,h2,c[10];
int n,i,m,num1,num2,t;

bool IsKing(char a){
	return (a==k);
}

int CNum(char a){
	switch (a){
		case '1':return 1;
		case 'A':return 1;
		case 'a':return 1;
		case '2':return 2;
		case '3':return 3;
		case '4':return 4;
		case '5':return 5;
		case '6':return 6;
		case '7':return 7;
		case '8':return 8;
		case '9':return 9;
		case 'J':return 11;
		case 'Q':return 12;
		case 'K':return 13;
		case 'j':return 11;
		case 'q':return 12;
		case 'k':return 13;
	}
}

bool camp(){
	if (h1==h2) return num1>num2;
	if (IsKing(h1)) return 1;
	if (IsKing(h2)) return 0;
	return num1>num2;
}

int main(){
	scanf("%d",&n);
	getchar();
	for (i=0;i<n;++i){
		k=getchar();
		getchar();
		m=0;
		while ((h1=getchar())!='\n'){
			++m;
			c[m]=h1;
			if (c[m]==' ') t=m;
		}
		if (t==4) {
			num1=10;
			h1=c[3];
		} else {
			num1=CNum(c[1]);
			h1=c[2];
		}
		if (m-t==3) {
			num2=10;
			h2=c[m];
		} else {
			num2=CNum(c[m-1]);
			h2=c[m];
		}
		if (camp()) printf("YES\n");
			else printf("NO\n");
	}
	return 0;
}
