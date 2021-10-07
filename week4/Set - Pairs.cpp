int pairs(int k, vector<int> arr) {
    int n = arr.size(), count = 0;
    set<int> s(arr.begin(), arr.end());
    set<int>::iterator it = s.begin();
    set<int>::iterator it2 = s.begin();
    while (it != s.end()) {
        int x = *it + k;
        for (it2 = s.begin(); it2 != s.end(); it2++) {
            if (*it2 == x) {
                count++;
                break;
            } else if (*it2 > x) {
                break;
            }
        }
        it++;
    }
    return count;
}
