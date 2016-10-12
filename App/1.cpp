#include<cstdio>
using namespace std;

const int startyear = 2016;
const int startmonth = 8;
const int startday = 29;

int CountDays(int year, int month, int day) {
    //返回当前是本年的第几天，year,month,day 表示现在的年月日，整数。
    int a[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
    int s = 0;
    for(int i = 0; i < month-1; i++) {
        s += a[i];
    }
    if(month > 2) {
        if(year % (year % 100 ? 4 : 400 ) ? 0 : 1)
            s += 29;
        else
            s += 28;
    }
    return (s + day);
}

int CountWeeks(int nowyear, int nowmonth, int nowday) {
    //返回当前是本学期第几周，nowyear,nowmonth,nowday 表示现在的年月日，整数。
    int ans = 0;
    if (nowyear == startyear) {
        ans = CountDays(nowyear, nowmonth, nowday) - CountDays(startyear, startmonth, startday) + 1;
        printf("%d\n", ans);
    } else {
        ans = CountDays(nowyear, nowmonth, nowday) - CountDays(nowyear, 1, 1) + 1;
        printf("%d\n", ans);
        ans += (CountDays(startyear, 12, 31) - CountDays(startyear, startmonth, startday) + 1);
        printf("%d\n", ans);
    }
    return (ans + 6) / 7;
}

bool IfWeeks(int nowweek, int dsz, int qsz, int jsz) {
/** nowweek 为的周数，整数
    dsz 为课程是单周上，还是双周上，1为单周，2为双周，0为每周都要上，整数
    qsz 为课程开始的周数，整数
    jsz 为课程结束的周数，整数 **/
    if (nowweek > jsz)
        return 0;
    if (nowweek < qsz)
        return 0;
    if (dsz == 0)
        return 1;
    return ((nowweek + dsz) % 2 == 0);
}

bool IfWeeks(int nowyear,int nowmonth,int nowday,int dsz,int qsz,int jsz) {
/** nowyear,nowmonth,nowday 表示现在的年月日，整数
    dsz 为课程是单周上，还是双周上，1为单周，2为双周，0为每周都要上，整数
    qsz 为课程开始的周数，整数
    jsz 为课程结束的周数，整数 **/
    int nowweek = CountWeeks(nowyear, nowmonth, nowday);
    return IfWeeks(nowweek, dsz, qsz, jsz);
}

int main() {
    return 0;
}
