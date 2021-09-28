SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    SinglyLinkedListNode* tmp = new SinglyLinkedListNode(data);
    if (!head) head = tmp;
    else {
        SinglyLinkedListNode* ptr = head;
        while (ptr->next) ptr = ptr->next;
        ptr->next = tmp;          
    }
    return head;
}