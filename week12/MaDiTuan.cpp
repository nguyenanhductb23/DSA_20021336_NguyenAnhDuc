#include <iostream>
#include <iomanip>
using namespace std;

void print(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(2) << setfill(' ') << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
} 

void diTuan(int i, int j, int num, int** arr, int n, int& ans) {
	arr[i][j] = num;
	if (num == n*n) {
		++ans;
		print(arr, n);
	}
	if (i-2 >= 0 && j-1 >= 0 && !arr[i-2][j-1]) {
		diTuan(i-2, j-1, num+1, arr, n, ans);
	}	
	if (i-2 >= 0 && j+1 < n && !arr[i-2][j+1]) {
		diTuan(i-2, j+1, num+1, arr, n, ans);
	}
	if (i+2 < n && j-1 >= 0 && !arr[i+2][j-1]) {
		diTuan(i+2, j-1, num+1, arr, n, ans);
	}
	if (i+2 < n && j+1 < n && !arr[i+2][j+1]) {
		diTuan(i+2, j+1, num+1, arr, n, ans);
	}
	if (i-1 >= 0 && j-2 >= 0 && !arr[i-1][j-2]) {
		diTuan(i-1, j-2, num+1, arr, n, ans);
	}
	if (i-1 >= 0 && j+2 < n && !arr[i-1][j+2]) {
		diTuan(i-1, j+2, num+1, arr, n, ans);
	}
	if (i+1 < n && j-2 >= 0 && !arr[i+1][j-2]) {
		diTuan(i+1, j-2, num+1, arr, n, ans);
	}
	if (i+1 < n && j+2 < n && !arr[i+1][j+2]) {
		diTuan(i+1, j+2, num+1, arr, n, ans);
	}
	arr[i][j] = 0;
}

void maDiTuan(int n) {
	int ans = 0;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int [n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	diTuan(2, 2, 1, arr, n, ans);
	cout << ans;
}

int main()
{
	int n;
	cin >> n;
	maDiTuan(n);
	return 0;
}