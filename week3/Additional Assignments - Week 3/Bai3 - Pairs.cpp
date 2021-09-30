int pairs(int k, vector<int> arr) {
    int n = arr.size(), count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i]-arr[j] == k || arr[i]-arr[j] == -k) {
                count++;
            }
        }
    }
    return count;
}

=> O(n^2)


int pairs(int k, vector<int> arr) {
    int n = arr.size(), count = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n-1; i++) {
        int target = abs(k) + arr[i];
        int mid, h = i+1, t = n-1;
        do {
            if (h > t) break;
            mid = (h+t)/2;
            if (arr[mid] < target) {
                h = mid + 1;
            } else {
                if (arr[mid] > target) {
                    t = mid - 1;
                } else {
                    count++;
                }
            }
        } while (arr[mid] != target);
    }
    return count;
}

=> O(nlogn)
