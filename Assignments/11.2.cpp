#include <iostream>
#include <algorithm>
using namespace std;

void dayCon(int* arr, int n, int m, int &s, int* x, int i, bool &ok) {
    if (ok || i == n) return;
    else {
        for (int j = 0; j < 2; j++) {
            x[i] = j;
            s += arr[i] * x[i];
            if (s == m) {
                cout << "YES";
                ok = true;
                return;
            }
	        dayCon(arr, n, m, s, x, i+1, ok);
	        s -= arr[i] * x[i];
        }
    }
}

int main() {
	int n, m;
	cin >> n >> m;
	int* arr = new int [n];
	int* x = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bool ok = false;
	int s = 0;
	dayCon(arr, n, m, s, x, 0, ok);
	if (!ok) cout << "NO";
	return 0;
}