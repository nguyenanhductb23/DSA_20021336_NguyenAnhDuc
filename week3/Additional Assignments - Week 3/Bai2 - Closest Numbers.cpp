vector<int> closestNumbers(vector<int> arr) {
    int n = arr.size();
    int mi = abs(arr[1] - arr[0]);
    vector<int> vt(0);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int diff = abs(arr[j]-arr[i]);
            if (diff == mi) {
                vt.push_back(arr[i]);
                vt.push_back(arr[j]);
            }   
            if (diff < mi) {
                mi = diff;
                vt.clear();	// => O(n)
                vt.push_back(arr[i]);
                vt.push_back(arr[j]);
            }
        }
    }
    sort(vt.begin(), vt.end());
    return vt;    
}

=> O(n^3)


vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end());	// => O(nlogn)
    int n = arr.size();
    int mi = abs(arr[1] - arr[0]);
    vector<int> vt(0);
    for (int i = 0; i < n-1; i++) {
        int diff = abs(arr[i+1]-arr[i]);
        if (diff == mi) {
            vt.push_back(arr[i]);
            vt.push_back(arr[i+1]);
        }   
        if (diff < mi) {
            mi = diff;
            vector<int> v(0);
            vt = v;
            vt.push_back(arr[i]);
            vt.push_back(arr[i+1]);
        }
    }
    return vt;    
}

=> O(nlogn)
