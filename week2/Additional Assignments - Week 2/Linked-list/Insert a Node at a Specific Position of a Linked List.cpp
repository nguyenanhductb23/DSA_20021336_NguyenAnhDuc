SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(data);
    SinglyLinkedListNode* ptr = head;
    for (int i = 0; i < position-1; i++) {
        ptr = ptr->next;
    }
    SinglyLinkedListNode* tmp = ptr->next;
    ptr->next = node;
    node->next = tmp;
    return head;
}
