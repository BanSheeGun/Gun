#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<string>
using namespace std;

char a[1000001];
char b[1000001];
int l1,l2,la,lb,t1,t2;

int pan() {
    int i;
    for (i = 0;i < l1; ++i) {
        if (a[t1 + i] < b[t2 + i]) {
            printf("<\n");
            return 0;
        } else {
            if (a[t1 + i] > b[t2 + i]) {
                printf(">\n");
                return 0;
            }
        }
    }
    printf("=\n");
    return 0;
}

int main()
{
    scanf("%s",a);
    scanf("%s",b);
    la = strlen(a);
    lb = strlen(b);
    t1 = 0;
    while (a[t1] == '0' && la != t1+1)
        ++t1;    
    t2 = 0;
    while (b[t2] == '0' && lb != t2+1)
        ++t2;

    l1 = la - t1;
    l2 = lb - t2;
    if (l1 < l2)
        printf("<\n");
    else {
        if (l1 > l2)
            printf(">\n");
        else 
            pan();
    }
    return 0;
}
