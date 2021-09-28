#include <iostream>
#include <stack>
using namespace std;

void transfer(stack<int>& src, stack<int>& des) {
    while (!src.empty()) {
        des.push(src.top());
        src.pop();
    }
}

int main() {
    stack<int> enq, deq;
    int n, typ, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> typ;
        switch (typ) {
            case 1:
                cin >> x;
                if (enq.empty()) transfer(deq, enq);
                enq.push(x);
                break;
            case 2:
                if (deq.empty()) transfer(enq, deq);
                deq.pop();
                break;
            case 3:
                if (deq.empty()) transfer(enq, deq);
                cout << deq.top() << endl;
                break;
            default: break;
        }
    }
    return 0;
}
