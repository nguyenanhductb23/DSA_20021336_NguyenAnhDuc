void print(Node* tmp) {
        if (!tmp) return;
        cout << tmp->data << ' ';
        print(tmp->next);
        bool ok = false;
        if (tmp->fatherNode) {
            if (tmp->fatherNode->next) {
                ok = true;
                print(tmp->fatherNode->next->firstChild);
            }
        }
        if (tmp->firstChild && ok)
            print(tmp->firstChild->firstChild);
        else print(tmp->firstChild);
    }