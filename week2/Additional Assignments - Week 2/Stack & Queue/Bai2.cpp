string isBalanced(string s) {
    int len = s.length();
    stack<char> ch;
    if (s[0]=='(' || s[0]=='[' || s[0]=='{') ch.push(s[0]);
    else return "NO";
    for (int i = 1; i < len; i++) {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{') ch.push(s[i]);
        else {
            if (ch.empty()) return "NO";
            if (s[i]==')') {
                if (ch.top()=='(') ch.pop();
                else return "NO";
            }
            if (s[i]=='}') {
                if (ch.top()=='{') ch.pop();
                else return "NO";
            }
            if (s[i]==']') {
                if (ch.top()=='[') ch.pop();
                else return "NO";
            }
        }
    }
    if (!ch.empty()) return "NO";
    return "YES";
}