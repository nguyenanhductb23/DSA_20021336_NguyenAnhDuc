vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    set<int> s(arr.begin(), arr.end()-1);
    set<int> s2(arr.begin()+1, arr.end());
    vector<int> vt(0);
    set<int>::iterator it2 = s2.begin();
    set<int>::iterator it = s.begin();
    int mi = *(it2) - *it;
    while (it != s.end()) {
        int diff = *(it2) - *it;
        if (diff == mi) {
            vt.push_back(*it);
            vt.push_back(*(it2));
        }   
        if (diff < mi) {
            mi = diff;
            vt.clear();
            vt.push_back(*it);
            vt.push_back(*(it2));
        }
        it++;   it2++;
    }
    return vt;    
}