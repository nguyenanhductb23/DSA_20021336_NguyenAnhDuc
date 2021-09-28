#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
	Node(int d) {
		data = d;
		prev = NULL;
		next = NULL;
	}
};

struct DoublyLinkedList {
	Node* head = NULL;
	Node* tail = NULL;
};

DoublyLinkedList* insertNodeAtTail(DoublyLinkedList* list, const int& x) {
	Node* n_node = new Node(x);
	if (list->head == NULL) {
		list->head = n_node;
		list->tail = n_node;
	}
	else {
		list->tail->next = n_node;
		n_node->prev = list->tail;
		list->tail = n_node;
	}
	return list;
}

void countTriplets(DoublyLinkedList* list) {
	int ans = 0;
	Node* tmp = list->head;
	while (tmp != NULL) {
		if (tmp != list->head && tmp != list->tail) {
			if (tmp->prev->data + tmp->data + tmp->next->data == 0) ans++;
		}
		tmp = tmp->next;
	}
	cout << ans;
}

int main()
{
	DoublyLinkedList* list = new DoublyLinkedList;
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		list = insertNodeAtTail(list, x);
	}
	countTriplets(list);
	return 0;
}