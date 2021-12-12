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

struct Graph {
    vector<Node*> n;
    vector<Edge*> e;
    map<Node*, bool> unvisited;
    
    bool hasCycle;

    void makeEdge(Node* v1, Node* v2) {
        v1->insertNext(v2);
        //v2->insertNext(v1);
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
        makeEdge(n[0], n[3]);
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
    
    //////////////////TopoSort//////////////////
    void topoSort(Node* startNode) {
        stack<Node*> st;
        stack<Node*> st2;
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
                unvisited[tmp] = false;
            } else {
                st2.push(topp);
                st.pop();
            } 
        }
        for (int i = 0; i < n.size(); i++) {
            if (unvisited[n[i]]) topoSort(n[i]);
        }
        while(!st2.empty()) {
            cout << st2.top()->value << ' ';
            st2.pop();
        }
    }
};

int main()
{
    Graph* g = new Graph();
    g->topoSort(g->n[1]);
    return 0;
}