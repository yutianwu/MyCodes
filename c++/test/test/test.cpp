#include <iostream>
using namespace std;

int partition(int *A, int begin, int end) {
	int key = A[end];
	int i = begin - 1;
	for (int j = begin; j < end; j++) {
		if (A[j] <= key) {
			int temp = A[++i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	int temp = A[++i];
	A[i] = A[end];
	A[end] = temp;
	return i;
}

void qsort(int *A, int begin, int end) {
	if (begin == end || begin > end) {
		return;
	}
	int mid = partition(A, begin, end);
	qsort(A, begin, mid - 1 );
	qsort(A, mid + 1, end);
}

void main () {
	int a[] = {5,4,3,2,1};
	qsort(a, 0, 4);
	for(int i = 0; i < 5; i++) {
		cout<<a[i]<<endl;
	}
}