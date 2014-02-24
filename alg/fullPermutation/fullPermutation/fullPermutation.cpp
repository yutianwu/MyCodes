//使用递归法完成全排列
/*
1、首先看最后两个数4, 5。 它们的全排列为4 5和5 4, 即以4开头的5的全排列和以5开头的4的全排列。
由于一个数的全排列就是其本身，从而得到以上结果。
2、再看后三个数3, 4, 5。它们的全排列为3 4 5、3 5 4、 4 3 5、 4 5 3、 5 3 4、 5 4 3 六组数。
即以3开头的和4,5的全排列的组合、以4开头的和3,5的全排列的组合和以5开头的和3,4的全排列的组合.
从而可以推断，设一组数p = {r1, r2, r3, ... ,rn}, 全排列为perm(p)，pn = p - {rn}。
因此perm(p) = r1perm(p1), r2perm(p2), r3perm(p3), ... , rnperm(pn)。当n = 1时perm(p} = r1。
*/

#include <iostream>
using namespace std;

int sum = 0;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void perm(int *A, int k, int m) {
	if (k > m) {
		for (int i = 0; i <= m; i++) {
			cout<<A[i]<<"\t";
		}
		cout << ++sum << endl;
	} else {
		for (int j = k; j <= m; j ++) {
			swap(&A[k], &A[j]);
			perm(A, k+1, m);
			swap(&A[k], &A[j]);
		}
	}
}

void main() {
	int a[5] = {1,2,3,4,5};
	perm(a, 0, 4);
	system("PAUSE");
}