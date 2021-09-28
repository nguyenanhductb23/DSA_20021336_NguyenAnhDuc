#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

struct Stack {
    int istack[MAX_SIZE];
    int top = -1;
    Stack() {}
    bool isEmpty() {
        if (top == -1) return true;
        return false;
    }
    void push(int x) {
        if (top == MAX_SIZE-1)
            cout << "Stack is full! Cannot push!\n";
        else {
            top++;
            istack[top] = x;
        }
    }
    void pop() {
        if (isEmpty()) cout << "Stack is empty! Cannot pop!\n";
        else top--;    
    }
    void print() {
        if (isEmpty()) cout << "Empty stack!";
        else {
            for (int i = 0; i <= top; i++)
                cout << istack[i] << ' ';
        }
    }
};

int main()
{
    Stack* q = new Stack;
    int n;    cin >> n;
    string s;    int x;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "push") {
            cin >> x;
            q->push(x);
        }
        if (s == "pop") q->pop();
    }
    q->print();
    return 0;
}
