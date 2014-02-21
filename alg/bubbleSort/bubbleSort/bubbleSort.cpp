#include <iostream>
using namespace std;

void bubbleSort(int *A, int n) {
	for (int i=0; i < n; i++) {
		for (int j = n-1; j >= i; j--) {
			if (A[j] < A[j-1]) {
				int tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
			}
		}
	}
}

void main() {
	int a[5] = {5,4,3,2,1};
	bubbleSort(a, 5);
	for (int i = 0; i < 5; i++) {
		cout<<a[i]<<endl;
	}
	system("PAUSE");
}