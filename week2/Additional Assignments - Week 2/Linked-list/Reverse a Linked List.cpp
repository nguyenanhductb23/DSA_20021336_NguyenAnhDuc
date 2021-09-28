SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {
    SinglyLinkedListNode *n_head = NULL, *foll = NULL, *curr = head;
    while (curr) {
        foll = curr->next;
        curr->next = n_head;
        n_head = curr;
        curr = foll;
    }
    return n_head;
}