#include <iostream>
using namespace std;

struct Node {
	int num;
	Node *next;
	Node():num(0),next(NULL) {}
}; 

Node *create() {
	Node *p1, *p2, *head;

	int num;
	cin>>num; 
	if (num == 0) {
		return NULL;
	} else {
		p1 = new Node();
		p1->num = num;
		head = p1;
	}

	while (true) {
		cin>>num;
		if (num == 0) {
			return head;
		}
		p2 = new Node();
		p2->num = num;
		p1->next = p2;
		p1 = p1->next;
	}
}

void main() {
	Node *head = create();
	while (head != NULL) {
		cout<<head->num<<endl;
		head = head->next;
	}
}