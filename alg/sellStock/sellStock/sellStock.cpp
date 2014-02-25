/*
Best Time to Buy and Sell Stock 
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

最大子数组问题
《算法导论》中引入这个问题是通过股票的购买与出售，经过问题转换，将前一天的当天的股票差价重新表示出来，即转为了一个最大子数组的问题，转的内容是：

13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7

找到这连续的16个数里面的连续和最大的子数组；

假定我们要寻找子数组A[low..high]的最大子数组，使用分治法意味着我们要将子数组划分为两个规模尽可能相等的子数组。也就是说，找到子数组的中央位置，比如mid，然后求解两个子数组A[low..mid]和A[mid + 1..high]。所以，A[low..high]的任何连续子数组A[i..j]所处的位置必然是三种情况之一：

1.完全位于子数组A[low..mid]中， 因此low<=i<=j<=mid;

2.完全位于子数组A[mid + 1..high]中，因此mid<=i<=j<=high;

3.跨越了中点，因此low<=i<=mid
因此，A[low..high]的一个最大子数组所处的位置必然是这三种情况之一。实际上，A[low..high]的一个最大子数组必然是完全位于A[low..mid]中、完全位于A[mid + 1..high]中或者跨越中点的所有子数组中和最大者。



*/

#include <iostream>
#include <vector>

using namespace std;

int findMaxCrossSubarray(int *A, int low, int mid, int high) {
	int leftSum = A[mid];
	int sum = A[mid];
	for (int i=mid-1; i>=low; i--) {
		sum += A[i];
		if (sum > leftSum) {
			leftSum = sum;
		}
	}

	int rightSum = A[mid+1];
	sum = A[mid+1];
	for(int j=mid+2; j<=high; j++) {
		sum += A[j];
		if (sum > rightSum) {
			rightSum = sum;
		}
	}

	return rightSum + leftSum;
}

int findMaxSubarray(int *A, int low, int high) {
	if (low == high) {
		return A[low];
	} else {
		int mid = (low+high)/2;
		int leftSum = findMaxSubarray(A, low, mid);
		int rightSum = findMaxSubarray(A, mid+1, high);
		int crossSum = findMaxCrossSubarray(A, low, mid, high);
		
		if(leftSum >= rightSum && leftSum >= crossSum) {
			return leftSum;
		} else if (rightSum >= leftSum && rightSum >= crossSum) {
			return rightSum;
		} else {
			return crossSum;
		}
	}
}

void main() {
	int a[] = {13, -3, -25, 20, 5};
	cout<<findMaxSubarray(a, 0, 4);
	system("PAUSE");
}