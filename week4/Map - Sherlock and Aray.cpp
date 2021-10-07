string balancedSums(vector<int> arr) {
    int n = arr.size();
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m.insert(pair<int,int> (i, arr[i]));
    }
    int left_sum = 0, right_sum = 0;
    map<int,int>::iterator it = m.begin();
    for (it++; it != m.end(); it++) 
        right_sum += it->second;
    if (left_sum == right_sum) return "YES";
    for (int i = 0; i < n-1; i++) {
        left_sum += m.at(i);
        right_sum -= m.at(i+1);
        if (left_sum == right_sum) return "YES";
    }
    return "NO";
}