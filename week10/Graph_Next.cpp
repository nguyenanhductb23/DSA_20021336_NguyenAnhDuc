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

void makeEdge(Node* v1, Node* v2) {
    v1->insertNext(v2);
    v2->insertNext(v1);
}

struct Graph {
    map<Node*, bool> unpassed;
    vector<Node*> n;
    Graph() {
        for (int i = 0; i < 8; i++) {
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
        makeEdge(n[0], n[3]);
        for (int i = 0; i < 8; i++) {
            unpassed[n[i]] = true;
        }
    }
    
    void resetUnpassed() {
        for (map<Node*, bool>::iterator it = unpassed.begin(); it != unpassed.end(); it++) {
            it->second = true;
        }
    }
    
    Node* nextToGo(Node* node) {
        vector<Node*> vt = node->nextNodes;
        for (int i = 0; i < vt.size(); i++) {
            if (unpassed[vt[i]]) {
                return vt[i];
            }
        }
        return NULL;
    }
    
    //////////////////DFS//////////////////////
    void recursionDFS(Node* node, stack<Node*> &st) {
        if (!node) {
            st.pop();
        } else {
            unpassed[node] = false;
            st.push(node);
            cout << node->value << ' ';
        }
        if (st.empty()) return;
        recursionDFS(nextToGo(st.top()), st);
    }
    
    void DFS(Node* startNode) {
        stack<Node*> st;
        recursionDFS(startNode, st);
    }
    
    //////////////////BFS//////////////////////
    void recursionBFS(Node* node, queue<Node*> q) {
        if (!node) {
            q.pop();
        } else {
            unpassed[node] = false;
            q.push(node);
            cout << node->value << ' ';
        }
        if (q.empty()) return;
        recursionBFS(nextToGo(q.front()), q);
    }
    
    void BFS(Node* startNode) {
        queue<Node*> q;
        recursionBFS(startNode, q);
    }
};

int main()
{
    Graph* g = new Graph();
    
    g->DFS(g->n[1]);
    g->resetUnpassed();
    cout << endl;
    g->BFS(g->n[1]);
    return 0;
}

