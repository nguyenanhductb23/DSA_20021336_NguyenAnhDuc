string balancedSums(vector<int> arr) {
    int sz = arr.size();
    int left_sum = 0, right_sum = 0;
    for (int i = 1; i < sz; i++)
        right_sum += arr[i]; 
    for (int i = 1; i < sz; i++) {
        left_sum += arr[i-1];
        right_sum -= arr[i];
        if (left_sum == right_sum) return "YES";
    }
    return "NO";
}
	--> O(n)


string balancedSums(vector<int> arr) {
    int n = arr.size();
    for (int pos = 0; pos < n; pos++) {
        int left_sum = 0, right_sum = 0;
        for (int i = 0; i < pos; i++) {
            left_sum += arr[i];
        }
        for (int i = pos+1; i < n; i++) {
            right_sum += arr[i];
        }
        if (left_sum == right_sum) return "YES";
    }
    return "NO";
}
	--> O(n^2)