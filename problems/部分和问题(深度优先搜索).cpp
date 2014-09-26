/*
p30
给定整数 a 1 、a 2 、…、a n ，判断是否可以从中选出若干数，使它们的和恰好为 k。
*/

#include <iostream>
using namespace std;

const int MAX_N = 20;

int a[MAX_N];
int k;

/*
	此题为经典的深度优先搜索，特征就是一个问题共分几步，每步都有几种可能，
	我们可以通过递归来实现这样的问题
*/
bool rec(int i, int j) {
	bool res = false;

	if (i == n) {
		if (j == 0) {
			res = true;
		} 	
	} else if (j < a[i]) {
		res = rec(i + 1, j);
	} else {
		res = rec(i + 1, j) || rec(i + 1, j - a[i]);
	}

	return res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	cin>>k;

	if (rec(0, k)) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}
}