#include <iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (equal(x, 0.0) && n < 0) {
            throw runtime_error("invalid input");
        }
        if (n < 0 ) return 1.0 / power(x, n * (-1));
        return power(x,n);
    }
private:
    double power(double x, unsigned int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double half = power(x, n >> 1);
        if (n & 0x1) return half*half*x;
        return half * half;
    }
    bool equal(double x, double y) {
        if ( (x - y > -0.000001) && (x - y < 0.000001) ) {
            return true;
        }
        return false;

    }
};

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
	Solution sol;
	sol.pow(1.00000, -2147483648);
}