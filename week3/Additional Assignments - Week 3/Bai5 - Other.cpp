#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, count = 0;      cin >> n;
    int* a = new int [n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n-2; i++) {
        int h = i+1, t = n-1;
        while (h < t) {
            if (a[i] + a[h] + a[t] == 0) {
                cout << a[i] << ' ' << a[h] << ' ' << a[t] << endl;
                h++;
            } else {
                t--;
            }
        }
    }
    return 0;
}

// => O(n^2)



/**int main()
{
    int n, count = 0;      cin >> n;
    int* a = new int [n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = j+1; k < n; k++) {
                if (a[i]+a[j]+a[k] == 0) 
                    cout << a[i] << a[j] << a[k] << endl;
            }
        }
    }
    cout << count;
    return 0;
}

=> O(n^3)
*/
