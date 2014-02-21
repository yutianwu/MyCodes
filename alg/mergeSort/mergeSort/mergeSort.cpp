#include <iostream>
using namespace std;

void merge(int *A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1+1];
	int *R = new int[n2+1];
	int i, j, k;

	//初始化左右数组
	for (i = 0; i < n1; i++) {
		L[i] = A[p+i];
	} 
	for (j = 0; j < n2; j++) {
		R[j] = A[q+j+1];
	}
	L[n1] = 100000;
	R[n2] = 100000;

	//合并左又数组
	i = 0;
	j = 0;

	for (k = p; k <= r; k ++) {
		if (L[i] < R[j]) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int *A, int p, int r) {
	int q = (p + r)/2;
	if (p < r) {
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}

void main() {
	int a[4] = {5, 4, 3, 2};
	mergeSort(a, 0, 3);
	for(int i=0; i<4; i++) {
		cout<<a[i]<<endl;
	}
	system("PAUSE");
}