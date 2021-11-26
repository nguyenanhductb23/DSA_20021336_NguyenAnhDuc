#include <iostream>
using namespace std;

void print(char** arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
} 

bool isOk(int ii, int jj, char** arr, int n) {
	for (int i = 0; i < ii; i++) {
		if (arr[i][jj] == 'x') return false;
		if (arr[i][ii+jj-i] == 'x') return false;
		if (i-ii+jj >= 0 && arr[i][i-ii+jj] == 'x') return false;
	}
	return true;
}

void xep1(int ii, char** arr, int n, int &ans) {
	if (ii == n) {
		print(arr,n);
		++ans;
	}
	for (int j = 0; j < n; j++) {
		if (isOk(ii, j, arr, n)) {
			arr[ii][j] = 'x';
			xep1(ii+1, arr, n, ans);
			arr[ii][j] = '-';
		}
	}
}

char** xepHau(int n) {
	int ans = 0;
	char** arr = new char* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char [n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = '-';
		}
	}
	xep1(0, arr, n, ans);
	cout << ans;
}

int main()
{
	int n;
	cin >> n;
	xepHau(n);
	return 0;
}