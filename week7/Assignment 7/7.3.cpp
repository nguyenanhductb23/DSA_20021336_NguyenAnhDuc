#include <iostream>
#include <cmath>

using namespace std;

int gcd(int x, int y) {
    if (x == 0) return abs(y);
    if (y == 0) return abs(x);
    if (y > x) return gcd(x, y % x);
    return gcd(x % y, y);
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y);
    return 0;
}