#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
FILE *Fin= fopen("file.in" , "r"),
	*Fout= fopen("file.out", "w");
const int MaxN= 55;
char s[MaxN][MaxN*100],*p[MaxN],tot,tmp[MaxN];
int N,len,cnt;
bool cmp(char*a,char*b){
	return strcmp(a,b)<0;
}
int main(){
	fscanf(Fin,"%d",&N);
	for(int i= 0;i< N;++ i){
		fscanf(Fin,"%s",s[i]);
		p[i]= s[i];
	}
	sort(p,p+N,cmp);
//	for(int i= 0;i< N;++ i)puts(p[i]);
	char*hd= p[0],*pre;
	while(*hd && *hd!='/'){
		fputc(*hd,Fout);
		hd++;
	}
	fputc('\n',Fout);
	len= hd-p[0];
	for(int i= 0;i< N;++ i)
		p[i]+= len;
	for(int i= 0;i< N;++ i){
		if(i==0){
			hd= p[i];
			while(*hd){
				if(*hd=='/'){
					cnt++;
					for(int i= 0;i< cnt;++ i)
						if(i==cnt-1)
							fputs("|",Fout);
						else
							fputs("|    ",Fout);
					fprintf(Fout,"----");
					hd++;
					while(*hd && *hd!='/'){
						fputc(*hd,Fout);
						hd++;
					}
					fputc('\n',Fout);
				}
			}
		}else{
			hd= p[i];
			pre= p[i-1];
			cnt= 0;
			while(*hd && *pre && *hd==*pre)
				hd++,pre++;
			while(hd>p[i] && *hd!='/')
				hd--;
			for(char*j= p[i];j!=hd;++ j)
				cnt+= (*j=='/');
			while(*hd){
				if(*hd=='/'){
					cnt++;
					for(int i= 0;i< cnt;++ i)
						if(i==cnt-1)
							fputs("|",Fout);
						else
							fputs("|    ",Fout);
					fprintf(Fout,"----");
					hd++;
					while(*hd && *hd!='/'){
						fputc(*hd,Fout);
						hd++;
					}
					fputc('\n',Fout);
				}
			}
		}
	}
//	system("pause");
	return 0;
}
