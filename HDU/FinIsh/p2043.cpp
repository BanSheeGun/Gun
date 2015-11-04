#include<iostream>
#include<string.h>

using namespace std;

int main(){
	int n,i;
    scanf("%d",&n);
    getchar();
    int n1,n2,n3,n4,j,l;
    for (i=1;i<=n;++i){
    	char a[51];
    	scanf("%s",a);
    	l=strlen(a);
    	n1=0;n2=0;n3=0;n4=0;
    	for (j=0;j<l;++j){
    		if (('0'<=a[j])&&(a[j]<='9')) {n1=1;}
    		if (('a'<=a[j])&&(a[j]<='z')) {n2=1;}
    		if (('A'<=a[j])&&(a[j]<='Z')) {n3=1;}	
    		if ('~'==a[j]) {n4=1;}
    		if ('!'==a[j]) {n4=1;}
    		if ('@'==a[j]) {n4=1;}
    		if ('#'==a[j]) {n4=1;}
    		if ('$'==a[j]) {n4=1;}
    		if ('%'==a[j]) {n4=1;}
    		if ('^'==a[j]) {n4=1;}
    	}
        int s=n1+n2+n3+n4;
        if ((s>=3)&&((8<=l)&&(l<=16))) {
        	printf("YES\n");
        } else {
        	printf("NO\n");
        }
    }
}
