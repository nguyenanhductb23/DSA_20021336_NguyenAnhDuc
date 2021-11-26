#include <iostream>
#include <algorithm>
using namespace std;

vector<int> unlimitedATM(vector<int> arr, int n) {
	int sz = arr.size();
	sort(arr.begin(), arr.end());
	vector<int> vt(sz, 0);
	int remaining = n, pos = sz-1;
	while (pos >= 0 && remaining > 0) {
		vt[pos] = remaining / arr[pos];
		remaining = remaining % arr[pos]; 
		pos--;
	}
	vt.push_back(n-remaining);
	return vt;
} 

vector<int> ATM(vector<int> arr, vector<int> num, int n) {
	int sz = arr.size();
	//sort(arr.begin(), arr.end());
	vector<int> vt(sz, 0);
	int remaining = n, pos = sz-1;
	while (pos >= 0 && remaining > 0) {
		vt[pos] = min(remaining / arr[pos], num[pos]);
		remaining -= vt[pos] * arr[pos]; 
		pos--;
	}
	vt.push_back(n-remaining);
	return vt;
}

int main() {
	vector<int> arr = {1,2,5,10,20,50,100,200,500};
	vector<int> num = {2,15,1,2,3,0,5,0,0};
	int n;
	cin >> n;
	vector<int> vt = ATM(arr, num, n);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << ": " << vt[i] << endl;
	}
	cout << "Rut duoc: " << vt[arr.size()];
	return 0;
}