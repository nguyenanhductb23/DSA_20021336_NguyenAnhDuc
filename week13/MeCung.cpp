#include <iostream>
using namespace std;

const int dx[] = {0, 1, -1, 0};
const int dy[] = {1, 0, 0, -1};

void timDuongDi(int** arr, int m, int n, int i, int j) {
    if (m-1 == j && n-1 == i) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << arr[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int t = 0; t < 4; t++) {
        int i1 = i+dy[t], j1 = j+dx[t];
        if (i1 < n && j1 < m && i1 >= 0 && j1 >= 0 && arr[i1][j1] == 0) {
            arr[i1][j1] = 2;
            timDuongDi(arr, m, n, i1, j1);
            arr[i1][j1] = 0;
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int [m];
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    arr[0][0] = 2;
    int len = 0;
    timDuongDi(arr, m, n, 0, 0);
    cout << len;
    
    return 0;
}