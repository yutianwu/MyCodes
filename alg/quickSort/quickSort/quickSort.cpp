/*
快速排序结合了插入排序和归并排序的优点，在原地排序并且期望运行时间为O(nlgn),思想主要是分治法
主要思路:
1.从数列中挑出一个元素，称为 "基准"（pivot）
2.重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作。
3.递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。

伪代码:
QUICK-SORT(A, p, r)
	if p<r
		then q<-PARTITION(A, p, r)
			QUICK-SORT(A, p, q-1)
			QUICK-SORT(A, q+1, r)

最好运行情况：每次q = n/2，这种情况下相当于归并排序的递归树，时间复杂度为nlgn
最坏运行情况:数组是已经排好序的或者是倒序的，这种情况下时间复杂度为n^2,与插入排序无异
期望运行时间为O(nlgn)
*/

#include <iostream>
using namespace std;

int partition(int *A, int p, int r) {
	int x = A[r];
	int i = p-1;
	for (int j = p; j <= r - 1; j ++) {
		if (A[j] <= x) {
			i++;

			//交换A[i],A[j]
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

void quickSort(int *A, int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}

void main() {
	int a[5] = {5,4,3,2,1};
	quickSort(a, 0, 4);
	for (int i = 0; i< 5; i++) {
		cout<<a[i]<<endl;
	}

	system("PAUSE");
}