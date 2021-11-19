#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct Node {
    int value;
    vector<Node*> nextNodes;
    
    Node() {}
    Node(int val) {
        value = val;
    }
    Node(int val, vector<Node*> nodes) {
        value = val;
        nextNodes = nodes;
    }
    
    void insertNext(Node* n_node) {
        int val = n_node->value;
        int idx = nextNodes.size();
        while (idx && nextNodes[idx-1]->value > val) {
            idx--;
        }
        nextNodes.push_back(n_node);
        for (int i = nextNodes.size()-1; i > idx; i--) {
            nextNodes[i] = nextNodes[i-1];
        }
        nextNodes[idx] = n_node;
    }
};

struct Edge {
    int value;
    Node* n1;
    Node* n2;
    Edge() {}
    Edge(Node* _n1, Node* _n2, int val) {
        n1 = _n1;
        n2 = _n2;
        value = val;
    }
    
    Edge(Node* _n1, Node* _n2) {
        n1 = _n1;
        n2 = _n2;
        value = 1;
    }
    
    ~Edge() {
        vector<Node*> nn1 = n1->nextNodes;
        vector<Node*> nn2 = n2->nextNodes;
        for (int i = 0; i < nn1.size(); i++) {
            if (nn1[i] == n2) {
                nn1.erase(nn1.begin() + i);
                break;
            }
        }
        for (int i = 0; i < nn2.size(); i++) {
            if (nn2[i] == n1) {
                nn2.erase(nn2.begin() + i);
                break;
            }
        }
    }
};

/**void makeEdge(Node* v1, Node* v2) {
    v1->insertNext(v2);
    v2->insertNext(v1);
}*/

struct Graph {
    vector<Node*> n;
    vector<Edge*> e;
    map<Node*, bool> unvisited;
    
    bool hasCycle;

    void makeEdge(Node* v1, Node* v2) {
        v1->insertNext(v2);
        v2->insertNext(v1);
        e.push_back(new Edge(v1, v2));
    }
    
    bool hasEdge(Node* v1, Node* v2) {
        for (int i = 0; i < v1->nextNodes.size(); i++) {
            if (v1->nextNodes[i] == v2) return true;
        }
        return false;
    }

    Graph() {
        for (int i = 0; i < 9; i++) {
            n.push_back(new Node(i));
        }
        makeEdge(n[1], n[2]);
        makeEdge(n[1], n[4]);
        makeEdge(n[1], n[5]);
        makeEdge(n[3], n[2]);
        makeEdge(n[4], n[2]);
        makeEdge(n[3], n[4]);
      //makeEdge(n[0], n[3]);
        makeEdge(n[5], n[4]);
        makeEdge(n[3], n[6]);
        makeEdge(n[3], n[7]);
        makeEdge(n[0], n[8]);
        for (int i = 0; i < 9; i++) {
            unvisited[n[i]] = true;
        }
        hasCycle = false;
    }
    
    int index(Node* node) {
        for (int i = 0; i < n.size(); i++) {
            if (n[i] == node) return i;
        }
        return -1;
    }
    
    void resetUnvisited() {
        for (map<Node*, bool>::iterator it = unvisited.begin(); it != unvisited.end(); it++) {
            it->second = true;
        }
    }
    
    Node* nextToGo(Node* node) {
        vector<Node*> vt = node->nextNodes;
        for (int i = 0; i < vt.size(); i++) {
            if (unvisited[vt[i]]) {
                return vt[i];
            }
        }
        return NULL;
    }
    
    //////////////////DFS//////////////////////
    void DFS(Node* startNode) {
        stack<Node*> st;
        st.push(startNode);
        unvisited[startNode] = false;
        cout << startNode->value << ' ';
        Node* topp = new Node();
        Node* tmp = new Node();
        while (!st.empty()) {
            topp = st.top();
            tmp = nextToGo(topp);
            if (tmp) {
                st.push(tmp);
                cout << tmp->value << ' ';
                unvisited[tmp] = false;
            } else st.pop();
        }
        resetUnvisited();
    }
    
    //////////////////BFS//////////////////////
    void BFS(Node* startNode) {
        queue<Node*> q;
        q.push(startNode);
        unvisited[startNode] = false;
        Node* topp = new Node();
        while (!q.empty()) {
            topp = q.front();
            cout << topp->value << ' ';
            q.pop();
            for (int i = 0; i < topp->nextNodes.size(); i++) {
                if (unvisited[topp->nextNodes[i]]) {
                    q.push(topp->nextNodes[i]);
                    unvisited[topp->nextNodes[i]] = false;
                }
            }
        }
        resetUnvisited();
    }

    /////////////////Đếm số thành phần liên thông//////////////////
    int numOfComponents() {
        map<Node*, int> component_id;
        int ans = 0, nsz = n.size(), esz = e.size();
        for (int i = 0; i < esz; i++) {
            Node* x = e[i]->n1;
            Node* y = e[i]->n2;
            if (!component_id[x] && !component_id[y]) {
                component_id[x] = ++ans;
                component_id[y] = ans;
            } else if (!component_id[y]) {
                component_id[y] = component_id[x];
            } else if (!component_id[x]) {
                component_id[x] = component_id[y];
            } else {
                if (component_id[x] == component_id[y]) hasCycle = true;
                else {
                    for (int t = 0; t < nsz; t++) {
                        int tmp = component_id[y];
                        if (component_id[n[t]] == tmp) component_id[n[t]] = component_id[x];
                        if (component_id[n[t]] == ans) component_id[n[t]] = tmp;
                    }
                }
            }
        }
        for (int i = 0; i < nsz; i++) {
            if (!component_id[n[i]]) ans++;
        }
        return ans;
    }
    
    /////////////////Khử chu trình//////////////////
    void discardCycle() {
        map<Node*, int> component_id;
        int ans = 0, nsz = n.size(), esz = e.size();
        for (int i = 0; i < esz; i++) {
            Node* x = e[i]->n1;
            Node* y = e[i]->n2;
            if (!component_id[x] && !component_id[y]) {
                component_id[x] = ++ans;
                component_id[y] = ans;
            } else if (!component_id[y]) {
                component_id[y] = component_id[x];
            } else if (!component_id[x]) {
                component_id[x] = component_id[y];
            } else {
                if (component_id[x] == component_id[y]) {
                    e[i] = NULL;
                    e.erase(e.begin() + i);
                } else {
                    int tmp = component_id[y];
                    for (int t = 0; t < nsz; t++) {
                        if (component_id[n[t]] == tmp) component_id[n[t]] = component_id[x];
                        if (component_id[n[t]] == ans) component_id[n[t]] = tmp;
                    }
                }
            }
        }
    }
    
    /////////////////Đường đi qua ít đỉnh nhất//////////////////
    int** fastestPath() {
        int nsz = n.size();
        int** dist = new int* [nsz];
        for (int i = 0; i < nsz; i++) {
            dist[i] = new int [nsz];
            for (int j = 0; j < nsz; j++) {
                if (hasEdge(n[i], n[j])) dist[i][j] = 1;
                else dist[i][j] = 100000;
            }
        }
        for (int k = 0; k < nsz; k++) {
            for (int i = 0; i < nsz; i++)
                for (int j = 0; j < nsz; j++)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
        }
        return dist;
    }
};

int main()
{
    Graph* g = new Graph();
    g->DFS(g->n[1]);
    cout << endl << g->e.size() << endl;
    g->BFS(g->n[1]);
    cout << endl << g->hasCycle << '\n';
    cout << g->numOfComponents();
    cout << '\n' << g->hasCycle << '\n';
    //g->discardCycle();
    cout << g->e.size() << endl;
    cout << g->fastestPath()[1][7];
    return 0;
}