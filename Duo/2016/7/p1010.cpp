#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct T {
    int x;
    int t;

    inline bool operator < (T b) const {
        return t < b.t;
    }
};


int ttt, i, n, t;
char s[7];
T a;

int main() {
    ttt = 0;
    while (scanf("%d", &n), n != 0) {
        ++ttt;
        printf("Case #%d:\n", ttt);
        t = 0;
        priority_queue<T> A, B;
        for (i = 1; i <= n; ++i) {
            scanf("%s", s);
            if (s[0] == 'p' && s[1] == 'o') {
                scanf("%s", s);
                if (s[0] == 'A') {
                    printf("%d\n", A.top().x);
                    A.pop();
                } else {
                    printf("%d\n", B.top().x);
                    B.pop();
                }
            } else 
                if (s[1] == 'u') {
                    ++t;
                    scanf("%s%d", s, &a.x);
                    a.t = t;
                    if (s[0] == 'A') {
                        A.push(a);
                    } else {
                        B.push(a);
                    }
                } else {
                    if (A.size() < B.size()) {
                        while (!A.empty()) {
                            a = A.top();
                            B.push(a);
                            A.pop();
                        }
                    } else {
                        while (!B.empty()) {
                            a = B.top();
                            A.push(a);
                            B.pop();
                        }
                    }
                    scanf("%s", s); scanf("%s", s);
                    if (s[0] == 'B' && B.size() != 0) swap(A, B);
                    if (s[0] == 'A' && A.size() != 0) swap(A, B);
                }
        }
    }
    return 0;
}