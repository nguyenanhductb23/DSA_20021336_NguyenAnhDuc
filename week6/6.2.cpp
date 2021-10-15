#include <iostream>
#include <algorithm>
using namespace std;

const int NUM = 9;

void selectionSort(int* arr, const int &n) {
    for (int sorted = 0; sorted < n-1; sorted++) {
        int iMin = sorted;
        for (int i = sorted+1; i < n; i++)
            if (arr[i] < arr[iMin]) iMin = i;
        swap(arr[iMin], arr[sorted]);
    }
}

void bubbleSort(int* arr, const int &n) {
    for (int sorted = 0; sorted < n-1; sorted++) {
        for (int i = 0; i < n-1-sorted; i++)
            if (arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
    }
}

void insertionSort(int* arr, const int &n) {
    for (int sorted = 1; sorted < n; sorted++) {
        int i = sorted - 1,  tmp = arr[sorted];
        while (arr[i] > tmp && i >= 0) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = tmp;
    }
}

int split(int* arr, int left, int right) {
    int apos = arr[left];
    while (left < right) {
        while (arr[left] < apos) left++;
        while (arr[right] > apos) right--;
        swap(arr[left], arr[right]);
    }
    return right;
}

void quickSort(int* arr, int left, int right) {
    int spl = split(arr, left, right);
    if (spl > left) swap(arr[left], arr[spl]);
    else return;
    quickSort(arr, left, spl-1);
    quickSort(arr, spl+1, right);
}

void print(int* arr, const int &n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main() {
    int arr[] = {2, 1, 10, 6, 3, 8, 7, 13, 20, 57, 60, -100, 2021, -5, -1, 0, 88, 101};
    //bubbleSort(arr, NUM*2);
    quickSort(arr, 0, NUM*2-1);
    print(arr, NUM*2);
    return 0;
}