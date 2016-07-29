#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

string a[71];
int i, n, j, ans;
string s;

int main() {
a[1] = "Cleveland Cavaliers";
a[2] = "Golden State Warriors";
a[3] = "San Antonio Spurs";
a[4] = "Miami Heat";
a[5] = "Miami Heat";
a[6] = "Dallas Mavericks";
a[7] = "L.A. Lakers";
a[8] = "L.A. Lakers";
a[9] = "Boston Celtics";
a[10] = "San Antonio Spurs";
a[11] = "Miami Heat";
a[12] = "San Antonio Spurs";
a[13] = "Detroit Pistons";
a[14] = "San Antonio Spurs";
a[15] = "L.A. Lakers";
a[16] = "L.A. Lakers";
a[17] = "L.A. Lakers";
a[18] = "San Antonio Spurs";
a[19] = "Chicago Bulls";
a[20] = "Chicago Bulls";
a[21] = "Chicago Bulls";
a[22] = "Houston Rockets";
a[23] = "Houston Rockets";
a[24] = "Chicago Bulls";
a[25] = "Chicago Bulls";
a[26] = "Chicago Bulls";
a[27] = "Detroit Pistons";
a[28] = "Detroit Pistons";
a[29] = "L.A. Lakers";
a[30] = "L.A. Lakers";
a[31] = "Boston Celtics";
a[32] = "L.A. Lakers";
a[33] = "Boston Celtics";
a[34] = "Philadelphia 76ers";
a[35] = "L.A. Lakers";
a[36] = "Boston Celtics";
a[37] = "L.A. Lakers";
a[38] = "Seattle Sonics";
a[39] = "Washington Bullets";
a[40] = "Portland Trail Blazers";
a[41] = "Boston Celtics";
a[42] = "Golden State Warriors";
a[43] = "Boston Celtics";
a[44] = "New York Knicks";
a[45] = "L.A. Lakers";
a[46] = "Milwaukee Bucks";
a[47] = "New York Knicks";
a[48] = "Boston Celtics";
a[49] = "Boston Celtics";
a[50] = "Philadelphia 76ers";
a[51] = "Boston Celtics";
a[52] = "Boston Celtics";
a[53] = "Boston Celtics";
a[54] = "Boston Celtics";
a[55] = "Boston Celtics";
a[56] = "Boston Celtics";
a[57] = "Boston Celtics";
a[58] = "Boston Celtics";
a[59] = "St. Louis Hawks";
a[60] = "Boston Celtics";
a[61] = "Philadelphia Warriors";
a[62] = "Syracuse Nats";
a[63] = "Minneapolis Lakers";
a[64] = "Minneapolis Lakers";
a[65] = "Minneapolis Lakers";
a[66] = "Rochester Royals";
a[67] = "Minneapolis Lakers";
a[68] = "Minneapolis Lakers";
a[69] = "Baltimore Bullets";
a[70] = "Philadelphia Warriors";
    cin >> n;
    getchar();
    for (i = 1; i <= n; ++i) {
        getline(cin,s);
        ans = 0;
        for (j = 1; j <= 70; ++j)
            if (s == a[j])
                ++ans;
        cout << "Case #" << i << ": " << ans << endl; 
    }
    return 0;
}