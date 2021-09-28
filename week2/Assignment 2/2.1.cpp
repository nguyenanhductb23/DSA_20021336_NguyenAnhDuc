#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;  cin >> n;
    int* a = new int [n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    int tmp = a[0], count = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i]==tmp) count++;
        else {
            ans += count*(count-1)/2;
            count = 1;    tmp = a[i];
        }
    }
    ans += count*(count-1)/2;
    cout << ans;
    return 0;
}