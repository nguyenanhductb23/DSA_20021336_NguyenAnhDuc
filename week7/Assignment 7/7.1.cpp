#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ifstream inFile("numbers.txt");
    ofstream outFile("numbers.sorted");
    if (inFile) {
        double num;
        vector<double> nums(0);
        while (!inFile.eof()) {
            inFile >> num;
            nums.push_back(num);
        }
        sort(nums.begin(), nums.end());
        if (outFile) {
            for (int i = 0; i < nums.size(); i++) {
                outFile << nums[i] << ' ';
            }
            outFile.close();
        }
        inFile.close();
    }
    return 0;
}

