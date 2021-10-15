#include <iostream>
using namespace std;

const int SIZE = 10000;

int search(int* id, int key) {
    int r = key % SIZE;
    int i = r;
    while (id[i] != key) {
        if (id[i] == -1) return -1;
        i = (i+1) % SIZE;
        if (i == r) return -1;
    }
    return i;
}

int main() {
    int* id = new int [SIZE];
    for (int i = 0; i < SIZE; i++)
        id[i] = -1;
    string* ten = new string [SIZE];
    string* lop = new string [SIZE];
    int i_id, r, n;      char ch;
    string task, i_ten, i_lop, trash;
    cin >> n;
    for (int i = 0; i < n; i++) {
        getline(cin, task, '(');
        if (task == "Insert") {
            cin >> i_id;
            cin >> ch;
            getline(cin, i_ten, ',');
            getline(cin, i_lop, ')');
            cin >> ch;  //(ch is \n)
            r = i_id % SIZE;
            while (id[r] != -1) {
                r = (r+1) % SIZE;
            }
            id[r] = i_id;
            ten[r] = i_ten;
            lop[r] = i_lop;
        }
        if (task == "Infor") {
            cin >> i_id;
            r = search(id, i_id);
            getline(cin, trash);
            if (r == -1) cout << "NA,NA\n";
            else cout << ten[r] << ',' << lop[r] << endl;
        }
        if (task == "Delete") {
            cin >> i_id;
            r = search(id, i_id);
            getline(cin, trash);
            if (r == -1) cout << "ID does not exist.\n";
            else {
                id[r] = -1;
                ten[r] = "";
                lop[r] = "";
            }
        }
    }
    return 0;
}