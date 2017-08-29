#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include <queue> 
using namespace std;
template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}
int n,m,q1,q2;

const int maxn = 400005; 
int a[maxn];
int toleft[25][maxn];
int T[25][maxn];

void build(int l,int r,int dep){
    if(l == r) return;
    int mid = (l+r)/2;
    int same = mid - l + 1;
    for(int i=l;i<=r;i++)
        if(T[dep][i] < a[mid])
            same--;
    int ls = l, rs = mid + 1;
    for(int i=l;i<=r;i++){
        int flag = 0;
        if((T[dep][i]==a[mid]&&same>0)||(T[dep][i]<a[mid])){
            T[dep+1][ls] = T[dep][i];
            ls++;
            flag = 1;
            if(T[dep][i] == a[mid])
                same--;
        } else {
            T[dep+1][rs] = T[dep][i];
            rs++;
        }
        toleft[dep][i] = toleft[dep][i-1] + flag;
    }
    build(l,mid,dep+1);
    build(mid+1,r,dep+1);
}

int query(int l,int r,int k,int L,int R,int dep){
    if(l == r)
        return T[dep][l];
    int mid = (L+R)/2;
    int x = toleft[dep][l-1] - toleft[dep][L-1];
    int y = toleft[dep][r] - toleft[dep][L-1];
    int ry = r - L - y;
    int cnt = y - x;
    int rx = l - L - x;
    if(cnt >= k)
        return query(L + x, L + y - 1, k, L, mid, dep + 1);
    else
        return query(mid + rx + 1, mid + 1 + ry, k - cnt, mid + 1, R, dep + 1);
}

int l,r,x,k1,k2;

int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++){
        read(a[i]);
        T[0][i]=a[i];
    }
    sort(a+1,a+1+n);
    build(1,n,0);
    for(int i=1;i<=m;i++) {
    read(l);read(r);read(x);read(k1);read(k2);
    if(k1 > r - l + 1) q1 = -1; else q1 = query(l,r,k1,1,n,0);
    if(k2>r-l+1)q2 = -1; else {
        int L=1,R=r-l+1, kid;
        while(L<=R){
            int M = (L+R)/2;
            int tmp = query(l,r,M,1,n,0);
            if(tmp>x){
                R=M-1;
                kid = M;
            } else L = M + 1;
        } 
        int tt = kid + k2 - 1;
        if( kid + k2 - 1 > r - l + 1) q2 = -1;
        else q2 = query(l,r,kid + k2 - 1,1,n,0);
    } 
    if(q1>x) q1 = -1; 
    if(q2<x) q2 = -1;
    printf("%d %d\n",q1,q2);
    }
    return 0;
} 