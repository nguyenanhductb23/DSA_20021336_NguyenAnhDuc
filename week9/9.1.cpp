#include <iostream>
#include <vector>

using namespace std;

int component(int n, vector<int> a, vector<int> b) {
    int ans = 0;
    int* arr = new int [n+1];
    for (int i = 1; i <= n; i++)
        arr[i] = 0;
    int m = a.size();
    for (int i = 0; i < m; i++) {
        int x = a[i],  y = b[i];
        if (!arr[x] && !arr[y]) {
            arr[x] = ++ans;
            arr[y] = ans;
        } else if (!arr[y]) {
            arr[y] = arr[x];
        } else if (!arr[x]) {
            arr[x] = arr[y];
        } else {
            for (int t = 1; t <= n; t++) {
                int tmp = arr[y];
                if (arr[t] == tmp) arr[t] = arr[x];
                if (arr[t] == ans) arr[t] = tmp;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) ans++;
    }
    return ans;
}

int main()
{
    int n, m, x, y;
    vector<int> a(0), b(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
    cout << component(n, a, b);

    return 0;
}
