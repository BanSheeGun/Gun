#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

char a;

int main() {
    while (~scanf("%c", &a)) {
        if (a == '1') printf("`");
        else if (a == '2') printf("1");
        else if (a == '3') printf("2");
        else if (a == '4') printf("3");
        else if (a == '5') printf("4");
        else if (a == '6') printf("5");
        else if (a == '7') printf("6");
        else if (a == '8') printf("7");
        else if (a == '9') printf("8");
        else if (a == '0') printf("9");
        else if (a == '-') printf("0");
        else if (a == '=') printf("-");
        else if (a == 'W') printf("Q");
        else if (a == 'E') printf("W");
        else if (a == 'R') printf("E");
        else if (a == 'T') printf("R");
        else if (a == 'Y') printf("T");
        else if (a == 'U') printf("Y");
        else if (a == 'I') printf("U");
        else if (a == 'O') printf("I");
        else if (a == 'P') printf("O");
        else if (a == '[') printf("P");
        else if (a == ']') printf("[");
        else if (a == '\\') printf("]");
        else if (a == 'S') printf("A");
        else if (a == 'D') printf("S");
        else if (a == 'F') printf("D");
        else if (a == 'G') printf("F");
        else if (a == 'H') printf("G");
        else if (a == 'J') printf("H");
        else if (a == 'K') printf("J");
        else if (a == 'L') printf("K");
        else if (a == ';') printf("L");
        else if (a == '\'') printf(";");
        else if (a == 'X') printf("Z");
        else if (a == 'C') printf("X");
        else if (a == 'V') printf("C");
        else if (a == 'B') printf("V");
        else if (a == 'N') printf("B");
        else if (a == 'M') printf("N");
        else if (a == ',') printf("M");
        else if (a == '.') printf(",");
        else if (a == '/') printf(".");
        else printf("%c", a);
    }
    return 0;
}
