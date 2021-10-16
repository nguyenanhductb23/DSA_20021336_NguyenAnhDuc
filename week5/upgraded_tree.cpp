#include <iostream>
#include <vector>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    //Node cha
    Node* parent;
    //Các node con
    vector<Node*> children;

public:
    Node() {
        parent = NULL;
        data = 0;
    }

    Node(int data) {
        parent = NULL;
        this->data = data;
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một vector các Node, với Node gốc là nodes[0]
    vector<Node*> nodes;

public:
    Tree() {}
    // Các hàm khởi tạo khác nếu cần thiết

    vector<Node*> getNodes() {
        return nodes;
    }

    Node* find(int d) {
        for (int i = 0; i < nodes.size(); i++)
            if (nodes[i]->data == d) return (nodes[i]);
        return NULL;
    }

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        Node* n_node = new Node(data);
        if (nodes.size() == 0) {
            Node* root = new Node(father);
            nodes.push_back(root);
        }
        Node* par_node = find(father);
        if (!par_node) return false;
        vector<Node*> siblings = par_node->children;
        for (int i = 0; i < siblings.size(); i++)
            if (siblings[i]->data == data) return false;
        n_node->parent = par_node;
        nodes.push_back(n_node);
        (par_node->children).push_back(n_node);
        return true;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data) {
        Node* r_node = find(data);
        if (!r_node) return 0;
        vector<Node*> vt = r_node->parent->children;
        for (int i = 0; i < vt.size(); i++)
            if (vt[i]->data == data) vt.erase(vt.begin()+i);
        int count = 0;
        remove(r_node, count);
        return count;
    }

    void remove(Node* node, int &count) {
        if (!node) return;
        vector<Node*> vt = node->children;
        for (int i = 0; i < vt.size(); i++)
            remove(vt[i], count);
        delete node;
        node = NULL;
        count++;
    }

    // Hàm in ra các Node theo thứ tự preorder
    //Để duyệt toàn bộ cây, node truyền vào phải là root
    void preorder(Node* node) {
        cout << node->data << ' ';
        if (node->children.size() == 0) return;
        for (int i = 0; i < node->children.size(); i++) {
            preorder(node->children[i]);
        }
    }

    // Hàm in ra các Node theo thứ tự postorder
    //Để duyệt toàn bộ cây, node truyền vào phải là root
    void postorder(Node* node) {
        for (int i = 0; i < node->children.size(); i++) {
            postorder(node->children[i]);
        }
        cout << node->data << ' ';
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes[i]->children.size() > 2) return false;
        }
        return true;
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree() {
        for (int i = 0; i < nodes.size(); i++) {
            vector<Node*> vt = nodes[i]->children;
            if (vt.size() > 2) return false;
            if (vt.size() == 2) {
                if (vt[0]->data > nodes[i]->data) return false;
                if (vt[1]->data < nodes[i]->data) return false;
            }
        }
        return true;
    }

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree() {
        for (int i = 0; i < nodes.size(); i++) {
            vector<Node*> vt = nodes[i]->children;
            for (int j = 0; j < vt.size(); j++)
                if (vt[j]->data > nodes[i]->data) return false;
        }
        return true;
    }

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder() {
        if (isBinaryTree()) {
            miniInorder(nodes[0]);
        }
    }

    void miniInorder(Node* node) {
        if (node->children.size() > 0) miniInorder(node->children[0]);
        cout << node->data << ' ';
        if (node->children.size() > 1) miniInorder(node->children[1]);
    }

    // Hàm trả về độ cao của cây
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

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        Node* node = find(data);
        if (!node) return -1;
        return depth(node);
    }

    int depth(Node* node) {
        int d = 0;
        while (node->parent) {
            node = node->parent;
            d++;
        }
        return d;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves() {
        int leaves = 0;
        for (int i = 0; i < nodes.size(); i++) {
            if ((nodes[i]->children).size() == 0) {
                leaves++;
            }
        }
        return leaves;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax() {
        int mx = nodes[0]->data;
        for (int i = 1; i < nodes.size(); i++)
            if (nodes[i]->data > mx) mx = nodes[i]->data;
        return mx;
    }

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild() {
        int mx = nodes[0]->children.size();
        for (int i = 1; i < nodes.size(); i++)
            if (nodes[i]->children.size() > mx) mx = nodes[i]->children.size();
        return mx;
    }
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    Tree* tree = new Tree();
    int par[] = {1, 1, 2, 2, 5, 7, 8, 8, 3, 6, 3};
    int val[] = {2, 3, 4, 5, 7, 8, 9, 10, 6, 11, 12};
    for (int i = 0; i < 11; i++) tree->insert(par[i], val[i]);
    for (int i = 13; i < 20; i++) tree->insert(12, i);
    for (int i = 20; i <= 30; i++) tree->insert(i-3, i);
    // Test thử các hàm của lớp cây
    tree->preorder(tree->getNodes()[0]);
    cout << endl << tree->remove(3) << endl;
    //cout << endl << tree->depth(29) << endl << tree->height() << endl << tree->numOfLeaves();
    tree->preorder(tree->getNodes()[0]);
    cout << '\n' << tree->isBinaryTree();

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    //tree->inorder();
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}
