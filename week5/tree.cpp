#include <iostream>
using namespace std;

// Một Node trong cây
class Node {
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;

    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    Node* next;

public:
    Node() {
        data = 0;
        fatherNode = NULL;
        firstChild = NULL;
        next = NULL;
    }

    Node(int data, Node* parent) {
        this->data = data;
        fatherNode = parent;
        firstChild = NULL;
        next = NULL;
    }

    int numOfChildren() {
        int count = 0;
        Node* tmp = firstChild;
        while (!tmp) {
            tmp = tmp->next;
            count++;
        }
        return count;
    }

    friend class Tree;
};

// Lớp Cây
class Tree {
    // Chứa một Node gốc
    Node* root;
public:
    Tree() {
        root = NULL;
    }
    // Các hàm khởi tạo khác nếu cần thiết

    Node* getRoot() {
        return root;
    }

    Node* find(Node* node, int data, Node* ans) {
        if (!node) return NULL;
        if (node->data == data) ans = node;
        if (ans) return ans;
        else ans = find(node->firstChild, data, ans);
        if (ans) return ans;
        else ans = find(node->next, data, ans);
        return ans;
    }

    Node* find(int data) {
        if (!root) return NULL;
        Node* tmp = root;
        while (true) {
            if (tmp->data == data) return tmp;
            while (tmp->firstChild) {
                tmp = tmp->firstChild;
                if (tmp->data == data) return tmp;
            }
            while (tmp->next) {
                tmp = tmp->next;
                if (tmp->data == data) return tmp;
            }
            if (!(tmp->firstChild) && tmp->fatherNode) {
                while (!(tmp->next)) tmp = tmp->fatherNode;
                tmp = tmp->next;
            }
        }
        return NULL;
    }
    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data) {
        if (!root) {
            root = new Node(father, NULL);
        }
        Node* par = find(father);
        if (!par) return false;
        Node* n_node = new Node(data, par);
        Node* tmp = par->firstChild;
        if (!tmp) par->firstChild = n_node;
        else {
            if (tmp->data == data) return false;
            while (tmp->next) {
                if (tmp->data == data) return false;
                tmp = tmp->next;
            } 
            tmp->next = n_node;
        }
        return true;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    void miniRemove(Node* node, int &count) {
        if (!node) return;
        else count++;
        miniRemove(node->firstChild, count);
        if (node->firstChild) miniRemove(node->firstChild->next, count);
        delete node;
    }
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    int remove(int data) {
        Node* r_node = find(data);
        Node* par_node = r_node->fatherNode;
        Node* tmp = par_node->firstChild;
        if (tmp == r_node) 
            par_node->firstChild = r_node->next;
        else {
            while (tmp->next != r_node) tmp = tmp->next;
            tmp->next = r_node;
        }
        if (!r_node) return 0;
        int count = 0;
        miniRemove(r_node, count);
        return count;
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << ' ';
        preorder(node->firstChild);
        preorder(node->next);
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->firstChild);
        postorder(node->next);
        cout << node->data << ' ';
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree() {
        if (!root) return true;
        Node* tmp = root;
        while (true) {
            if (tmp->numOfChildren() > 2) return false;
            while (tmp->firstChild) {
                tmp = tmp->firstChild;
                if (tmp->numOfChildren() > 2) return false;
            }
            while (tmp->next) {
                tmp = tmp->next;
                if (tmp->numOfChildren() > 2) return false;
            }
            if (!(tmp->firstChild) && tmp->fatherNode) {
                while (!(tmp->next)) tmp = tmp->fatherNode;
                tmp = tmp->next;
            }
        }
        return true;
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree();

    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree();

    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder();

    // Hàm trả về độ cao của cây
    int height() {
        if (!root) return -1;
        int d, h = 0;
        Node* tmp = root;
        while (true) {
            while (tmp->firstChild) {
                tmp = tmp->firstChild;
            }
            d = depth(tmp);
            if (d > h) h = d;
            while (tmp->next) {
                tmp = tmp->next;
            }
            if (!(tmp->firstChild) && tmp->fatherNode) {
                while (!(tmp->next)) tmp = tmp->fatherNode;
                tmp = tmp->next;
            }
        }
        return h;
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data) {
        Node* node = find(data);
        return depth(node);
    }

    int depth(Node* node) {
        int d = 0;
        while (node->fatherNode) {
            node = node->fatherNode;
            d++;
        }
        return d;
    }

    // Hàm đếm số lượng lá
    int numOfLeaves();

    // Hàm trả về Node có giá trị lớn nhất
    int findMax();

    // Hàm trả về Node có nhiều con nhất
    int findMaxChild();
};

int main(int argc, char const *argv[]) {
    // Tạo ra một cây ngẫu nhiên có tối thiểu 30 Node
    Tree* tree = new Tree();
    int par[] = {1, 1, 2, 2, 5, 7, 8, 8, 3, 6, 3};
    int val[] = {2, 3, 4, 5, 7, 8, 9, 10, 6, 11, 12};
    for (int i = 0; i < 11; i++) tree->insert(par[i], val[i]);
    //for (int i = 13; i < 20; i++) tree->insert(12, i);
    //for (int i = 20; i <= 30; i++) tree->insert(i-1, i);
    // Test thử các hàm của lớp cây
    tree->preorder(tree->getRoot());
    //cout << endl << tree->remove(2) << endl;
    cout << tree->depth(8) << tree->height();
    //tree->preorder(tree->getRoot());
    //cout << endl << tree->isBinaryTree();

    // Tạo ra một cây thoả mãn tính chất là Binary Search Tree và test lại
    
    // Tạo ra một cây thoả mãn tính chất là Max Heap Tree và test lại
    return 0;
}
