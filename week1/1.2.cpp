#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Point {
public:
    double x, y;
    Point() {
        x = 0;  y = 0;
    }
    Point(double _x, double _y) {
        x = _x;  y = _y;
    }
};

class Line {
public:
    Point A, B;
    Line() {
        A(0,0);  B(0,0);
    }
    Line(Point _A, Point _B) {
        A = _A;  B = _B;
    }
    vector<double> coef() {  //Find a,b: y=ax+b
        vector<double> vt(0);
        if (A.x==B.x) {
            vt.push_back(A.x);
            return vt;
        }
        double a = (B.y-A.y)/(B.x-A.x);
        vt.push_back(a);
        vt.push_back(A.y-A.x*a);
        return vt;
    }
};

void intersect(Line d1, Line d2) {
    vector<double> v1 = d1.coef();
    vector<double> v2 = d2.coef();
    if (v1.size()==1) {
        if (v2.size()==1) {
            if (v1[0]==v2[0]) 
                cout << "MANY";
            if (v1[0]!=v2[0])    
                cout << "NO";
        }
        else {
            cout << fixed << setprecision(2) << v1[0] << ' ' << v2[0]*v1[0]+v2[1];
        }
        return;
    }
    if (v1.size()==1) {
        cout << fixed << setprecision(2) << v2[0] << ' ' << v2[0]*v1[0]+v1[1];
        return;
    }
    if (v1[0]==v2[0]) {
        if (v1[1]==v2[1]) cout << "MANY";
        else cout << "NO";
        return;
    }
    double xx = (v1[1]-v2[1])/(v2[0]-v1[0]);
    cout << fixed << setprecision(2) << xx << ' ' << v2[0]*xx+v2[1];
}

int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    Point A(x1,y1), B(x2,y2), C(x3,y3), D(x4,y4);
    Line d1(A,B), d2(C,D);
    intersect(d1,d2);
    return 0;
}