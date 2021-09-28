#include <iostream>
#include <queue>

using namespace std;

void print(queue<int> s) {
    while (!s.empty()) {
        cout << s.front() << ' ';
        s.pop();
    }
}

int main()
{
    queue<int> my_queue;
    queue<int> sub_queue;
    int n, x, mi;       
    cin >> n;
    int unsorted = n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        my_queue.push(x);
    }
    sub_queue = my_queue;
    while (!my_queue.empty()) my_queue.pop();
    while (unsorted) {
        mi = sub_queue.front();
        sub_queue.pop();
        for (int i = 0; i < unsorted-1; i++) {
            int tmp = sub_queue.front();
            if (tmp < mi) {
                sub_queue.push(mi);
                mi = tmp;
            }
            else sub_queue.push(tmp);
            sub_queue.pop();
        }
        my_queue.push(mi);
        unsorted--;
    }
    print(my_queue);
    return 0;
}
