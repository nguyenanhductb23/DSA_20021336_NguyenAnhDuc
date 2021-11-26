#include <iostream>
#include <algorithm>
using namespace std;

const int WEIGHT = 0;
const int VAL = 1;
const int QUAL = 2;
const int POS = 3;

bool soSanh(vector<double> a, vector<double> b) {
	if (a[QUAL] == b[QUAL]) return a[WEIGHT] > b[WEIGHT];
	return a[QUAL] > b[QUAL];
}

vector<int> knapsack(vector<double> w, vector<double> v, int n) {
	int sz = w.size();
	vector<vector<double>> obj;
	vector<int> vt(sz, 0);
	for (int i = 0; i < sz; i++) {
		obj.push_back({w[i], v[i], v[i] / w[i], i});
	}
	sort(obj.begin(), obj.end(), soSanh);
	double remaining = n, val = 0;
	for (int i = 0; i < sz && remaining > 0; i++) {
		int x = (int) (remaining / obj[i][WEIGHT]);
		vt[obj[i][POS]] = x;
		remaining -= x * obj[i][WEIGHT];
		val += x * obj[i][VAL];
	}
	vt.push_back(val);
	return vt;
}

int main() {
	vector<double> val = {1,200,5,10,20,50,100,200,500};
	vector<double> weight = {2,15,1,2,3,7,5,10,27};
	int n;
	cin >> n;
	vector<int> vt = knapsack(weight, val, n);
	for (int i = 0; i < weight.size(); i++) {
		cout << weight[i] << ", " << val[i] << ": " << vt[i] << endl;
	}
	cout << "Lay duoc: " << vt[val.size()];
	return 0;
}