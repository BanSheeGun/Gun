#include<cstdio>
#include<cstring>

using namespace std;

char a[2000];
int l, i;

char fan(char k) {
    switch (k) {
        case 'b': return 'd';
        case 'd': return 'b';
        case 'A': return 'A';
        case 'H': return 'H';
        case 'I': return 'I';
        case 'L': return 'L';
        case 'M': return 'M';
        case 'O': return 'O';
        case 'X': return 'X';
        case 'x': return 'x';
        case 'o': return 'o';
        case 'q': return 'p';
        case 'p': return 'q';
        case 'T': return 'T';
        case 'U': return 'U';
        case 'V': return 'V';
        case 'v': return 'v';
        case 'w': return 'w';
        case 'W': return 'W';
        case 'Y': return 'Y';
        default : return ' ';
    }
    return ' ';
}


int main() {
    scanf("%s", a);
    l = strlen(a);
    for (i = 0; i < l; ++i) {
        if (a[i] != fan(a[l - i - 1])) {
            printf("NIE\n");
            return 0;
        }
    }
    printf("TAK\n");
    return 0;
}