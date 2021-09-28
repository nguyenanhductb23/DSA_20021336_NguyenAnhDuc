#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string S = "", W;
    int Q, typ, ix;     cin >> Q;
    stack<string> sstack;
    sstack.push("");
    for (int i = 0; i < Q; i++) {
        cin >> typ;
        switch (typ) {
            case 1:
                //getline(cin, W);
                cin >> W;
                S += W;
                sstack.push(S);
                break;
            case 2:
                cin >> ix;
                S = S.substr(0,S.length()-ix);
                sstack.push(S);
                break;
            case 3:
                cin >> ix;
                cout << S[ix-1] << endl;
                break;
            case 4:
                sstack.pop();
                S = sstack.top();
                break;
            default: break;
        }
    }
    return 0;
}
