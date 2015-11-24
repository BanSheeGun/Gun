#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>

using namespace std;
priority_queue<int,vector<int>,less<int> > q;
priority_queue<int,vector<int>,less<int> > p;
priority_queue<int,vector<int>,less<int> > t;
int a,b,k,n,i;

int main()
{
    scanf("%d",&n);
    for (i = 1;i <= n; ++i) {
        scanf("%d",&k);
        q.push(k);
    }
    for (i = 1;i < n; ++i) {
        scanf("%d",&k);
        p.push(k);
    }
    t = p;
    p.push(-10);    
    for (i = 1;i <= n; ++i) {
        a = q.top();
        b = p.top();
        if (a == b) {
            q.pop();
            p.pop();
        } else {
            printf("%d\n",a);
            break;
        }
    }
    while (q.size() != 0) q.pop();
    for (i = 1;i < n-1; ++i) {
        scanf("%d",&k);
        q.push(k);
    }
    q.push(-10);
    p = t;   
    for (i = 1;i < n; ++i) {
        a = q.top();
        b = p.top();
        if (a == b) {
            q.pop();
            p.pop();
        } else {
            printf("%d\n",b);
            break;
        }
    }
    return 0;
}
