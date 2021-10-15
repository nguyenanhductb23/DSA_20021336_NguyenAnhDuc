#include <iostream>
#include <vector>
using namespace std;

const int MAX_SIZE = 100;

class Node {
public:
    int data;
    Node* parent;
    vector<Node*> children;

    Node() {}

    Node(int data) {
        parent = NULL;
        this->data = data;
    }
};

class Tree : public Node {
    vector<Node*> nodes;

public:
    Tree() {}

    vector<Node*> getNodes() {
        return nodes;
    }

    bool isEmpty() {
        return (nodes.size() == 0);
    }

    bool isBinaryTree() {
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->children.size() > 2) return false;
        }
        return true;
    }

    Node* find(int d) {
        for (int i = 0; i < nodes.size(); i++)
            if (nodes[i]->data == d) return (nodes[i]);
        return NULL;
    }

    void insert(int parent_val, int val) {
        Node* n_node = new Node(val);
        Node* par_node = find(parent_val);
        if (!par_node) {
            Node* root = new Node(parent_val);
            par_node = root;
            nodes.push_back(par_node);
        }
        n_node->parent = par_node;
        nodes.push_back(n_node);
        (par_node->children).push_back(n_node);
    }
    
    int depth(Node* node) {
        int d = 0;
        while (node->parent) {
            node = node->parent;
            d++;
        }
        return d;
    }

    int height() {
        int mx_d = 0, d = 0;
        for (int i = 0; i < nodes.size(); i++) {
            if ((nodes[i]->children).size() == 0) {
                d = depth(nodes[i]);
                if (d > mx_d) mx_d = d;
            }
        }
        return mx_d;
    }

    //Để duyệt toàn bộ cây, node truyền vào phải là root
    void preOrder(Node* node) {
        cout << node->data << ' ';
        if (node->children.size() == 0) return;
        for (int i = 0; i < node->children.size(); i++) {
            preOrder(node->children[i]);
        }
    }

    //Để duyệt toàn bộ cây, node truyền vào phải là root
    void postOrder(Node* node) {
        for (int i = 0; i < node->children.size(); i++) {
            postOrder(node->children[i]);
        }
        cout << node->data << ' ';
    }

    void miniInOrder(Node* node) {
        if (node->children.size() > 0) miniInOrder(node->children[0]);
        cout << node->data << ' ';
        if (node->children.size() > 1) miniInOrder(node->children[1]);
    }

    void inOrder() {
        if (!isBinaryTree()) {
            cout << "NOT BINARY TREE";
        } else {
            miniInOrder(nodes[0]);
        }
    }

};

int main() {
    Tree* tree = new Tree();
    int par[] = {1, 1, 2, 2, 5, 7, 2, 2, 3, 6, 3};
    int val[] = {2, 3, 4, 5, 7, 8, 9, 10, 6, 11, 12};
    for (int i = 0; i < 11; i++) tree->insert(par[i], val[i]);
    for (int i = 13; i < 20; i++) tree->insert(12, i);
    for (int i = 20; i <= 30; i++) tree->insert(i-3, i);
    cout << tree->height() << endl;
    cout << tree->depth(tree->find(5)) << endl;
    cout << (tree->isBinaryTree()) << endl;
    tree->preOrder((tree->getNodes())[0]);
    cout << endl;
    tree->postOrder((tree->getNodes())[0]);
    cout << endl;
    tree->inOrder();
    return 0;
} 