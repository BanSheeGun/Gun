#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const double eps = 1e-16;

struct Point {
    double x, y, z;

    Point operator - (const Point & b) const {
        Point c;
        c.x = x - b.x;
        c.y = y - b.y;
        c.z = z - b.z;
        return c;
    }
    Point operator + (const Point & b) const {
        Point c;
        c.x = x + b.x;
        c.y = y + b.y;
        c.z = z + b.z;
        return c;
    }
};

struct Plane {
    double a, b, c, d;
};

void get_panel(Point p1,Point p2,Point p3, Plane &aa) {  
    aa.a = ( (p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y) );  
    aa.b = ( (p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z) );   
    aa.c = ( (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x) );  
    aa.d = ( 0-(aa.a*p1.x+aa.b*p1.y+aa.c*p1.z) );
}  

double f(Plane a, Point b) {
    return a.a * b.x + a.b * b.y + a.c * b.z + a.d;
}


vector<Point> plane[105];
int sum[105];
bool t[105];
int n, i, j;
Point view, now;
Point no[105];
Plane nop[105];

bool pan1(Point now, int x) {
    if (fabs(f(nop[x], view)) < eps)
        return 0;
    for (int i = 0; i < sum[x]; ++i) {
        Plane z;
        get_panel(plane[x][i],  plane[x][(i+1)%sum[x]], view, z);
        double xx = f(z, no[x]);
        double yy = f(z, now);
        if (xx * yy < 0)
            return 0;
    }
    return 1;
}


int main() {
    string s;
    getline(cin, s);
    stringstream s1;
    s1 << s;
    s1 >> n;
    for (i = 1; i <= n; ++i) {
        int id;
        string s;
        sum[i] = 0;
        getline(cin, s);
        stringstream ss;
        ss << s;
        ss >> id;
        Point tmp;
        now.x = 0; now.y = 0; now.z = 0;
        while(ss >> tmp.x >> tmp.y >> tmp.z) {
            plane[i].push_back(tmp);
            now = now + tmp;
            ++sum[i];
        }
        now.x = now.x / sum[i];
        now.y = now.y / sum[i];
        now.z = now.z / sum[i];
        no[i] = now;
        get_panel(plane[i][0], plane[i][1], plane[i][2], nop[i]);
    }
    memset(t, 0, sizeof(t));
    cin >> view.x >> view.y >> view.z;
    for (i = 1; i <= n; ++i) {
        if (fabs(f(nop[i], view)) < eps)
            t[i] = 1;
        for (j = 1; j <= n; ++j)
            if (j != i && pan1(no[i], j)) {
                double xx = f(nop[j], no[i]);
                double yy = f(nop[j], view);
                if (xx * yy < 0 || fabs(xx) < eps)
                    t[i] = 1;
            }
    }
    for (i = 1; i <= n; ++i)
        if (t[i] == 0)
            printf("%d\n", i);
    return 0;
}