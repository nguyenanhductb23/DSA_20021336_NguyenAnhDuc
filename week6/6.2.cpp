#include <iostream>
#include <algorithm>
using namespace std;

const int NUM = 9;

void selectionSort(int* arr, const int &n) {
    for (int j = n-1; j >= 0; j--) {
        int iMax = 0;
        for (int i = 0; i <= j; i++)
            if (arr[i] > arr[iMax]) iMax = i;
        swap(arr[iMax], arr[j]);
    }
}

void print(int* arr, const int &n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int arr[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    selectionSort(arr, NUM);
    print(arr, NUM);
    return 0;
}