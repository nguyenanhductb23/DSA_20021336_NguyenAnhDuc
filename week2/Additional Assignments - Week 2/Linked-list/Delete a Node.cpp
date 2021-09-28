SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    if (position == 0) {
        SinglyLinkedListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    else {
        SinglyLinkedListNode* tmp = head;
        for (int i = 0; i < position-1; i++) {
            tmp = tmp->next;
        }
        SinglyLinkedListNode* ptr = tmp->next;
        if (!ptr) tmp = NULL;
        else 
            tmp->next = ptr->next;
        delete ptr;
    }
    return head;
}
