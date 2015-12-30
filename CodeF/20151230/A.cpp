#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

char a[100],b[100];
int n;

int main()
{
    scanf("%d%s%s",&n,b,a);
    if (a[0] == 'w') {
        switch(n) {
            case 1:printf("52\n");break;
            case 2:printf("52\n");break;
            case 3:printf("52\n");break;
            case 4:printf("52\n");break;
            case 5:printf("53\n");break;
            case 6:printf("53\n");break;
            case 7:printf("52\n");break;
            default :break;
        }
    } else {
        if (n<=29) printf("12\n");
        else {
            if (n<=30) printf("11\n");
                else printf("7\n");
        }
    }
    return 0;
}
