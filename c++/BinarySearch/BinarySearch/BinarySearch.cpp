#include <iostream>
using namespace std;

//二分查找的非递归实现
int BinarySearch(int *list, int num, int begin, int end) {
	if (list == NULL || begin > end || begin < 0 || end < 0) {
		return -1;
	}
	while (begin <= end) {
		int mid = begin + (end - begin)/2; //不要使用end+begin,可能会溢出
		if(list[mid] == num) {
			return mid;
		}
		if (list[mid] > num) {
			end = mid - 1;
		} else {
			begin = mid + 1;
		}
	}
	return -1;
}

//二分查找的递归实现
int BinarySearchRecursive(int *list, int num, int begin, int end) {
	if (list == NULL || begin > end || begin < 0 || end < 0) {
		return -1;
	}
	int mid = begin + (end - begin);
	if (list[mid] == num) {
		return mid;
	} else if (list[mid] > num) {
		return BinarySearchRecursive(list, num, begin, end - 1);
	} else {
		return BinarySearchRecursive(list, num, mid + 1, end);
	}
}

void main() {
	int a[] = {1,2,3,4,5};
	int place = BinarySearchRecursive(a, 2, 0, 4);
	cout << place<<endl;
}