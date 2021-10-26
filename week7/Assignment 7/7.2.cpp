#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ifstream inFile("Matrix.txt");
    ofstream outFile("Matrix.out");
    if (inFile) {
        int m, n;
        inFile >> m >> n;
        int** arr = new int* [m];
        for (int i = 0; i < m; i++) {
            arr[i] = new int [n];
            for (int j = 0; j < n; j++)
                inFile >> arr[i][j];
        }
        vector<int> index(4, -1);
        int mx = maxSumRectangle(arr, m, n, vt);
        
        if (outFile) {
            for (int i = 0; i < 4; i++) {
                outFile << index[i] << ' ';
            }
            outFile << mx;
            outFile.close();
        }
        inFile.close();
    }
    return 0;
}

