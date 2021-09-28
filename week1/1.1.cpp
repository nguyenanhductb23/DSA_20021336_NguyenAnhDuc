#include <iostream>

using namespace std;

int main()
{
    string s, ans;
    getline(cin, s);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        ans = s[i] + ans;
    }
    cout << ans;
    return 0;
}