#include <iostream>
#include <stack>

using namespace std;

void print(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
}

int main()
{
    stack<int> my_stack;
    stack<int> sub_stack;
    int n, x, mx;       
    cin >> n;
    int unsorted = n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        my_stack.push(x);
    }
    while (unsorted > 1) {
        mx = my_stack.top();
        my_stack.pop();
        for (int i = 0; i < unsorted-1; i++) {
            int tmp = my_stack.top();
            if (tmp > mx) {
                sub_stack.push(mx);
                mx = tmp;
            }
            else sub_stack.push(tmp);
            my_stack.pop();
        }
        my_stack.push(mx);
        for (int i = 0; i < unsorted-1; i++) {
            my_stack.push(sub_stack.top());
            sub_stack.pop();
        }
        unsorted--;
    }
    print(my_stack);
    return 0;
}
