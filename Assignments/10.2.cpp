#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 999;

struct Edge {
    int u, v;
    int w;
};

bool soSanh(const edge &a, const edge &b) {
    return a.w < b.w;
}

int c[N], x[N];

int find(int u) {
    if (c[u] != u) c[u] = find(c[u]);
    return c[u];
}

bool join(int u, int v) {
    u = find(u); v = find(v);
    if (u == v) return false;
    if (x[u] == x[v]) x[u]++;
    if (x[u] < x[v]) c[u] = v;
    else c[v]=u;
    return true;
}

int main() {
    int n, m; 
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) 
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), soSanh);

    for (int i=1; i<=n; i++) {
        c[i] = i;
        x[i] = 0;
    }
    int mst_weight = 0;
    for (int i = 0; i < m; i++) {
        if (join(edges[i].u, edges[i].v)) {
            mst_weight += edges[i].w;
        }
    }
    cout << mst_weight;
    return 0;
}