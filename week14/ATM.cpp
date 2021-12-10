#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int INF = 100000;

int atm_r(int* notes, int n, int m) {
    if (m == 0) return 0;
	if (n == 0 || notes[n-1] > m) return INF;
	return min(atm_r(notes, n-1, m), 1 + atm_r(notes, n, m - notes[n-1]));
}

int atm_d(int* notes, int n, int m) {
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m+1];
    }
    for (int i = 0; i <= m; i++)
        arr[0][i] = INF;
    for (int i = 0; i < n; i++) 
        arr[i][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (j >= notes[i]) {
                arr[i][j] = min(arr[i-1][j], 1 + arr[i][j - notes[i]]);
            } else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    return arr[n-1][m];
}

int main() {
	int notes[] = {3, 2};
	int notesd[] = {20, 3};
//	sort(notes, notes+2);
	int m;
	cin >> m;
//	cout << atm_r(notes, 2, m) << '\n';
	cout << atm_d(notesd, 2, m);
	return 0;
}