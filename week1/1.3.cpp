#include <iostream>

using namespace std;

int main()
{
    int a, b, d;
    cin >> a >> b;
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (a > 0 && b > 0) {
        if (a > b) a = a % b;
        else b = b % a;
    }
    d = a + b;
    cout << d;
    return 0;
}
