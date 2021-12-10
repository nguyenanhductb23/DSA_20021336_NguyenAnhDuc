#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int lcs_r(string a, string b) {
	if (a == "" || b == "") return 0;
	if (a[a.length()-1] != b[b.length()-1]) {
		return max(lcs_r(a, b.substr(0, b.length()-1)), lcs_r(a.substr(0, a.length()-1), b));
	} else {
		return 1 + lcs_r(a.substr(0, a.length()-1), b.substr(0, b.length()-1));
	}
}

int lcs_d(string a, string b) {
	int la = a.length(), lb = b.length();
	int** arr = new int* [la+1];
	for (int i = 0; i <= la; i++) {
		arr[i] = new int [lb+1];
		arr[i][0] = 0;
	}
	for (int i = 0; i <= lb; i++)
		arr[0][i] = 0;
	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			if (a[i-1] == b[j-1]) arr[i][j] = 1 + arr[i-1][j-1];
			else arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
		}
	}
	return arr[la][lb];
}

int main() {
	string a, b;
	cin >> a >> b;
	//cout << lcs_r(a,b);
	cout << lcs_d(a,b);
	return 0;
}