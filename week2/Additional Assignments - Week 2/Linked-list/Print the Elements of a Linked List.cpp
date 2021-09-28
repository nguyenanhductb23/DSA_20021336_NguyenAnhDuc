void printLinkedList(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* tmp = head;
    while (tmp) {
        cout << tmp->data << endl;
        tmp = tmp->next;
    }
}
