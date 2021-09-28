int sum(vector<int> &h) {
    int s = 0, sz = h.size();
    for (int i = 0; i < sz; i++)
        s += h[i];
    return s;
}
 
void pop(vector<int> &h, int &sum) {
    sum -= h[0];
    h.erase(h.begin());
}

int equalStacks(vector<int>& h1, vector<int>& h2, vector<int>& h3) {
    int sum1 = sum(h1), sum2 = sum(h2), sum3 = sum(h3);
    while (!(sum1==sum2 && sum2==sum3)) {
        int mi = min(min(sum1,sum2),sum3);
        while (sum1 > mi) pop(h1,sum1);
        while (sum2 > mi) pop(h2,sum2);
        while (sum3 > mi) pop(h3,sum3);
    }
    return sum1;
}