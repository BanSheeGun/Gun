#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

int n, i;

int main() {
    scanf("%d", &n);
    if (n == 1) {
        cout << "I hate it";
        return 0;
    }
    for (i = 1; i < n; ++i)
        if (i % 2 == 0)
            cout << " I love that";
        else 
            cout << " I hate that";
        if (n % 2 == 0)
            cout << " I love it";
        else 
            cout << " I hate it";
    return 0;
}