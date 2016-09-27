#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

string a[100];
int n, i, l;

inline bool Init() {
    if (getline(cin, a[1])) {
        if (a[1] == "0")
            return 1;
        n = 1;
        while (getline(cin, a[++n]), a[n] != "0");
        --n;
        return 1;
    }
    return 0;
}

inline int Paces(int n) {
    for (int i = 1; i <= n; ++i)
        printf("    ");
    return 0;
}

inline int find(int now) {
    int ans = 0;
    int l1 = a[now-1].length(); int l2 = a[now].length();
    for (int i = 0; i < l2; ++i) {
        if (i == l1) break;
        if (a[now-1][i] != a[now][i]) break;
        if (a[now-1][i] == '/') ++ans;
    }
    return ans;
}

inline bool cmp(string a, string b) {
    if (a == b) return 1;
    int l1, l2, t1 = 0, t2 = 0, i, t = 0;
    l1 = a.length(); l2 = b.length();
    for (i = 0; i < l1; ++i)
        if (a[i] == '/') ++t1;
    for (i = 0; i < l2; ++i)
        if (b[i] == '/') ++t2;
    for (i = 0; i < l1; ++i) {
        if (a[i] == '/') {
            if (b[i] == '/')
                ++t;
            else
                return 1;
        } else {
            if (b[i] == '/')
                return 0;
            else
                if (a[i] != b[i])
                    return (a[i] < b[i]);
        }
        if (t == t1)
            if (t == t2) {
            } else {
                return 0;
            }
        else {
            if (t == t2)
                return 1;
        }
    }
}

int j;

int main() {
    freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    a[0] = "0"; int T = 0;
    while (Init()) {
        printf("Case %d:\n", ++T);
        sort(a+1, a+1+n, cmp);
        for (i = 1; i <= n; ++i) {
            if (a[i] == a[i-1]) continue;
            l = find(i);
            int l1 = a[i].length(), t = 0;
            for (j = 0; j < l1; ++j) {
                if (a[i][j] == '/') ++t;
                if (t < l) continue;
                if (a[i][j] == '/') {
                    if (t != l) printf("\n");Paces(t);
                } else {
                    putchar(a[i][j]);
                }
            }
            putchar('\n');
        }
    }
    return 0; 
}