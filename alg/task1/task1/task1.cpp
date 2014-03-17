#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &A, int p, int r) {
	int x = A[r];
	int i = p-1;
	for (int j = p; j <= r - 1; j ++) {
		if (A[j] <= x) {
			i++;

			//½»»»A[i],A[j]
			int tmp = A[j];
			A[j] = A[i];
			A[i] = tmp;
		}
	}
	
	int tmp = A[i+1];
	A[i+1] = A[r];
	A[r] = tmp;

	return i+1;
}

void quickSort(vector<int> &A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void main() {
	//vector<int> ori;
	//ori.push_back(3);
	//ori.push_back(5);
	//ori.push_back(7);
	//ori.push_back(1);
	//ori.push_back(9);
	//ori.push_back(8);
	//vector<int> sorted(ori);

	//quickSort(sorted, 0, 4);
	//for (int i = 0; i< 5; i++) {
	//	cout<<sorted[i]<<endl;
	//}
	ListNode *head = &ListNode(1);
	ListNode *ori = head;
	head->next = &ListNode(2);
	head = head->next;
	head = &ListNode(3);
	head = head->next;
	head = &ListNode(4);
	head = head->next;
	head = &ListNode(5);
	while (ori->next != NULL) {
		cout<<ori->val<<endl;
	}
}