SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (head1 == NULL) {
        return head2;
    } else if (head2 == NULL) {
        return head1;
    }
    
    SinglyLinkedListNode* head = NULL;
    if (head1->data < head2->data) {
        head = head1;
        head1 = head1->next;
    } else {
        head = head2;
        head2 = head2->next;
    }
    
    SinglyLinkedListNode* n_head = head;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            n_head->next = head1;
            head1 = head1->next;
        } else {
            n_head->next = head2;
            head2 = head2->next;
        }
        n_head = n_head->next;
    }
    
    if (head1 == NULL) {
        n_head->next = head2;
    } else {
        n_head->next = head1;
    }

    return head;
}
