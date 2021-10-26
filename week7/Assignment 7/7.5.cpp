#include <iostream>
using namespace std;

void print(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i];
    cout << endl;
}

void duyet(int* arr, bool* appeared, int n, int k) {
    for (int i = 1; i <= n; i++) {
        if (!appeared[i]) {
            arr[k] = i;
            appeared[i] = true;
            if (k == n-1) {
                print(arr, n);
            }
            else duyet(arr, appeared, n, k+1);
            appeared[i] = false;
        }
        
    }
}

int main() {
    int n;
    cin >> n;
    int* arr = new int [n];
    bool* appeared = new bool [n+1];
    for (int i = 0; i < n; i++) {
        appeared[i] = false;
    }
    duyet(arr, appeared, n, 0);
    return 0;
}