#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<cstring>
using namespace std;
const int N = 200010;
typedef pair<int,int> aaa;
int aa[N], in[N], T, n, m, s, flag;
set<int>st[N], qry, pan;
set<aaa>e;
int dp[100][100];
int find1(int pos,int v){
    int l=1,r=pos;
    while(l<r){
        int mid=(l+r)>>1;
        int len=pos-mid+1;
        int now=pos,cur=-1;
        for(int i=17;i>=0;--i){
            if(len&(1<<i)){
                if(cur==-1)cur=dp[now][i];
                else cur=__gcd(cur,dp[now][i]);
                now-=(1<<i);
            }
        }
        if(cur<v)l=mid+1;
        else r=mid;
    }
    return (l+r)>>1;
}
void find(){
    queue<int>q;
    set<int>::iterator it = pan.begin();
    while (it != pan.end()) {q.push(*it);++it;}
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(set<int>::iterator it = qry.begin(); it != qry.end(); ){
            if(e.count(aaa(min(u, *it), max(u, *it))) == 0){
                q.push(*it);
                aa[*it] = aa[u]+1;
                set<int>::iterator tmp = it; tmp++;
                qry.erase(it);
                it = tmp;
            }
            else ++it;
        }
    }
}
int main() {
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m);
        memset(in, 0, sizeof(in));
        for(int i = 1; i <= n; ++i) st[i].clear();
        e.clear(); pan.clear(); qry.clear();
        for(int a, b, i = 0; i < m; ++i){
            scanf("%d%d", &a, &b);
            if(a > b) swap(a, b);
            in[a]++, in[b]++;
            st[a].insert(b);
            st[b].insert(a);
            e.insert(aaa(a, b));
        }
        scanf("%d", &s);
        for(int i = 1; i <= n; ++i){
            if(i == s) continue;
            if(st[s].count(i)) qry.insert(i);
            else aa[i] = 1, pan.insert(i);
        }
        flag = 0;
        for(int i = 1; i <= n; ++i){
            if(in[i] == 0){
                flag = 1;
                break;
            }
        }
        if(flag){
            set<int>::iterator it = qry.begin();
            while (it != qry.end()) {
                aa[*it] = 2;
                 ++it;
            }
        } else {
            find();
        }
        flag = 0;
        for(int i = 1; i <= n; ++i){
            if(i == s) continue;
            if(flag) 
                printf(" ");
            else 
                flag = 1;
            printf("%d", aa[i]);
        }
        printf("\n");
    }
    return 0;
}