#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

struct Queue {
    int iqueue[MAX_SIZE];
    int front = 0, rear = -1;
    Queue() {}
    bool isEmpty() {
        if (front > rear) return true;
        return false;
    }
    void enqueue(int x) {
        if (rear == MAX_SIZE-1) cout << "Queue is full! Cannot enqueue!\n";
    	else {
    	    rear++;
            iqueue[rear] = x;
    	}
    }
    void dequeue() {
        if (isEmpty()) cout << "Queue is empty! Cannot dequeue!\n";
        else {
            for (int i = 0; i < rear; i++)
                iqueue[i] = iqueue[i+1];
            rear--;
        }
    }
    void print() {
        if (isEmpty()) cout << "Empty queue!";
        else {
            for (int i = front; i <= rear; i++)
                cout << iqueue[i] << ' ';
        }
    }
};

int main()
{
    Queue* q = new Queue;
    int n;    cin >> n;
    string s;    int x;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "enqueue") {
            cin >> x;
            q->enqueue(x);
        }
        if (s == "dequeue") q->dequeue();
    }
    q->print();
    return 0;
}
