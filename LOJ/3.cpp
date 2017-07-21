#include<cstdio>
#include<iostream>
int T;
char ch;
int main() {
    freopen("copycat.in", "r", stdin);
    freopen("copycat.out", "w", stdout);
    scanf("%d", &T);
    getchar();
    while (T--) {
        while ((ch = getchar()) != '\n') {
            putchar(ch);
        }
        putchar('\n');
    }
    return 0;
}