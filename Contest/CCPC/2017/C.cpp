#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
int read_p,read_ca;
inline int read(){
    read_p=0;read_ca=getchar();
    while(read_ca<'0'||read_ca>'9') read_ca=getchar();
    while(read_ca>='0'&&read_ca<='9') read_p=read_p*10+read_ca-48,read_ca=getchar();
    return read_p;
}

int deg[3005];
int main(int argc, const char* agrv[]) {
    int T;
    T = read();
    while(T--) {
        memset(deg, 0, sizeof(deg));
        int n;
        n = read();
        for(int x, i = 1; i <= n; ++i) {
            for(int j = i+1; j <= n; ++j) {
                x = read();
                if(x == 0) continue;
                deg[i] ++;
                deg[j] ++;
            }
        }
        ll tot = (ll)n*(n-1)*(n-2)/6;
        ll sum = 0;
        for(int i = 1; i <= n; ++i) {
            sum += (ll)deg[i]*(n-deg[i]-1);
        }
        if(sum/2 == tot) printf("Great Team!\n");
        else printf("Bad Team!\n");
    }
}