#include <iostream>
using namespace std;

const int SIZE = 60;

struct Node {
    int id;
    string name;
    Node* next;
    Node() {
        id = -1;
        name = "";
        next = NULL;
    }
    Node(int mssv, string fullname) {
        id = mssv;
        name = fullname;
        next = NULL;
    }
};

class HashTable {
    Node** table;
public:
    HashTable() {
        table = new Node* [SIZE];
        for (int i = 0; i < SIZE; i++) {
            table[i] = NULL;
        }
    }

    void put(int mssv, string fullname) {
        //Khoi tao
        Node* n_node = new Node(mssv, fullname);
        //Them vao table
        int h = mssv % SIZE;
        if (table[h] == NULL) table[h] = n_node;
        else {
            n_node->next = table[h];
            table[h] = n_node;
        }
    }
    string get(int mssv) {
        int h = mssv % SIZE;
        for (Node* tmp = table[h]; tmp != NULL; tmp = tmp->next) {
            if (tmp->id == mssv) return tmp->name;
        }
        return "[Nobody]";
    }
    void remove(int mssv) {
        int h = mssv % SIZE;
        Node* tmp = table[h];
        if (tmp == NULL) return;
        if (tmp->id == mssv) {
            table[h] = table[h]->next;
            return;
        }
        for ( ; tmp->next != NULL; tmp = tmp->next) {
            if (tmp->next->id == mssv) {
                Node* t_next = tmp->next->next;
                tmp->next = t_next;
                return;
            }
        }
    }
};

int main(int argc, const char* argv[]) {
    HashTable* table = new HashTable();
    table->put(136, "N A Duc");
    table->put(1336, "Duc");
    table->put(1396, "N Duc");
    table->put(1276, "Ng Duc");
    table->put(1996, "Ng A Duc");
    table->put(1337, "Ng M Duc");
    cout << table->get(1996) << endl;
    table->remove(1996);
    table->remove(137);
    cout << table->get(1996) << endl;
    cout << table->get(1337) << endl;
    return 0;
}