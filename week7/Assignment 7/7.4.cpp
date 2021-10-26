#include <iostream>
using namespace std;

void print(int* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i];
    cout << endl;
}

void duyet(int* arr, int n, int k) {
    arr[k] = 0;
    if (k == n-1) print(arr, n);
    else duyet(arr, n, k+1);
    arr[k] = 1;
    if (k == n-1) print(arr, n);
    else duyet(arr, n, k+1);
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int [n];
    duyet(arr, n, 0);
    return 0;
}

