//堆排序
/*
	堆排序在这几种排序中是最复杂的一种，它也是使用递归法来实现的，
	它分为两步，
	第一步，建成一个初始的最大堆
	第二部，将数组的第一个元素和最后一个元素替换，再让新生成的堆编程一个最大堆，重复以前的步骤

	伪代码如下：
	HEAP-SORT(A)
		BUILD-MAX-HEAP(A)
		for i<-length[A] down to 2 
			do exchangeA[1] <-> A[j]
				heap-size <- heap-size[A]-1
				MAX-HEAPIFY(A, 1)
*/

#include <iostream> 
using namespace std;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void max_heapify(int *A, int k, int n) {
	int l = 2*k;
	int r = 2*k + 1;
	int largest = k;

	if (l <= n && A[l-1] > A[k-1]) {
		largest = l;
	}
	if (r <= n && A[r-1] > A[largest-1]) {
		largest = r;
	}

	if (largest != k) {
		swap(&A[k-1], &A[largest-1]);
		max_heapify(A, largest, n);
	}
}

void build_max_heap(int *A, int n) {
	for (int i = n/2; i >= 1; i --) {
		max_heapify(A, i, n);
	}
}

void heap_sort(int *A, int n) {
	build_max_heap(A, n);
	for (int i = n; i >= 2; i--) {
		swap(&A[0], &A[i-1]);
		max_heapify(A, 1, i-1);
	}
}

void main() {
	int a[5] = {5,4,3,2,1};
	heap_sort(a, 5);
	for (int i = 0; i < 5; i ++) {
		cout<<a[i]<<endl;
	}
	system("PAUSE");
}