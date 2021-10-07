#include <iostream>
using namespace std;

const int SIZE = 60;

class HashTable {
    int* id = new int [SIZE];
    string* name = new string [SIZE];
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            id[i] = -1;
            name[i] = "";
        }
    }
    int hash(int mssv) {
        int r = mssv % SIZE;
        int end_pos = (r-1) % SIZE;
        while (id[r] != -1) {
            if (id[r] == mssv) return r;
            if (r == end_pos) return -1;
            r = (r+1) % SIZE;
        }
        return r;
    }
    int search(int mssv) {
        int r = mssv % SIZE;
        int end_pos = (r-1) % SIZE;
        while (id[r] != mssv) {
            if (r == end_pos) return -1;
            r = (r+1) % SIZE;
        }
        return r;
    }
    void put(int mssv, string fullname) {
        int x = hash(mssv);
        id[x] = mssv;
        name[x] = fullname;
    }
    string get(int mssv) {
        int h = search(mssv);
        if (h == -1) return "[Nobody]";
        return name[h];
    }
    void remove(int mssv) {
        int h = search(mssv);
        id[h] = -1;
        name[h] = "";
    }
};

int main(int argc, const char* argv[]) {
    HashTable* table = new HashTable();
    table->put(1336, "N A Duc");
    table->put(1396, "N Duc");
    table->put(1276, "Ng Duc");
    table->put(1996, "Ng A Duc");
    table->put(1337, "Ng M Duc");
    cout << table->get(1336) << endl;
    cout << table->get(1276) << endl;
    cout << table->get(1335) << endl;
    return 0;
}