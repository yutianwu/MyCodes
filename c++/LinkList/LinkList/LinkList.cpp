#include <iostream>
using namespace std;

struct Node {
	int num;
	Node *next;
	Node():num(0),next(NULL) {}
}; 

Node *create() {
	Node *head = NULL;

	int num;
	cin>>num; 
	if (num == 0) {
		return head;
	} 
	head = new Node();
	head->num = num;
	Node *p = head;

	while (cin >> num) {
		if (num == 0) {
			return head;
		}
		Node *temp = new Node();
		temp->num = num;
		p->next = temp;
		p = p->next;
	}
}

void main() {
	Node *head = create();
	while (head != NULL) {
		cout<<head->num<<endl;
		head = head->next;
	}
}