#include <iostream>
#include <vector>
using namespace std;
const int INF = 100000;

vector<int> imin(int* arr, vector<int> S) {
    int m = 0;
    vector<int> vt(1, m);
    for (int i = 0; i < S.size(); i++) {
        if (arr[S[i]] < arr[S[m]]) {
            m = i;
            vt.clear();
            vt.push_back(i);
        }
        if (arr[S[i]] == arr[S[m]]) {
            vt.push_back(i);
        }
    }
    return vt;
}

int main()
{
    int n, m, x, y, src, des;
    cin >> n >> m >> src >> des;
    int** arr = new int* [n+1];
    int* D = new int [n+1];
    int* P = new int [n+1];
    for (int i = 0; i <= n; i++) {
        arr[i] = new int [n+1];
        for (int j = 0; j <= n; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    vector<int> S(0);
    for (int i = 1; i <= n; i++) 
        S.push_back(i);
    S.erase(S.begin() + src-1);
    for (int i = 1; i <= n; i++) 
        P[i] = 1;
    for (int i = 1; i <= n; i++)
        D[i] = arr[1][i];
    while (S.size()) {
        vector<int> vt = imin(D, S);
        for (int t = 0; t < vt.size(); t++) {
            int m = vt[t];
            int sm = S[m];
            if (D[sm] == D[des]) {
                cout << D[des] << endl;
                return 0;
            }
            S.erase(S.begin() + m);
            for (int i = 0; i < S.size(); i++) {
                if (D[S[i]] > D[sm] + arr[sm][i]) {
                    D[S[i]] = D[sm] + arr[sm][i];
                }
            }
        }
        
    }
    cout << INF;
    return 0;
}
