#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node() {}
    Node(int val) {
       data = val;
       next = NULL;
    }
};

void setnull(Node* &n) {
    n = NULL;  
}

Node* insert(Node* &head, const int& pos, const int& val) {
    Node* new_node = new Node(val);
    if (pos == 0) {
        new_node->next = head;
        head = new_node;
        return head;
    }
    Node* tmp = head;
    for (int i = 0; i < pos-1; i++) tmp = tmp->next;
    new_node->next = tmp->next;
    tmp->next = new_node;
    return head;
} 

Node* deleteNode(Node* &head, const int& pos) {
    if (pos == 0) {
        head = head->next;
        return head;
    }
    Node* tmp = head;
    for (int i = 0; i < pos-1; i++) tmp = tmp->next;
    Node* target = tmp->next;
    tmp->next = target->next;
    setnull(target);
    return head;
}

Node* formatList() {
    return NULL;
}

void print(Node* head) {
    for (Node* tmp=head; tmp!=NULL; tmp=tmp->next)
        cout << tmp->data << ' ';
}

int main()
{
    Node* list = new Node;
    setnull(list);
    int num;     cin >> num;
    string s;    int pos, x;
    for (int i = 0; i < num; i++) {
        cin >> s;
        if (s == "insert") {
            cin >> pos >> x;
            insert(list, pos, x);
        }
        if (s == "delete") {
            cin >> pos;
            deleteNode(list, pos);
        }
    }
    print(list);
    return 0;
}
