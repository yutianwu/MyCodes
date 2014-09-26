/*
此题见于挑战一书51页
*/
#include <iostream>
using namespace std;

const int MAX_N = 100;

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_N + 1];

/*
	这种解法算是动态规划的一个入门
	由于使用DFS会重复计算很多次rec(i,j)的结果，所以我们就可以定义一个数组来存储
	中间结果，这样就可以降低时间复杂度到O(n*W)，但是这需要O(n^2)的存储空间，以空间换时间，
	有利有弊
*/
int rec(int i, int j) {
	if (dp[i][j] >= 0) {
		return dp[i][j];
	}

	int res;
	if (i == n) {
		res = 0;
	} else if (j < w[i]) {
		res = rec(i + 1, j);
	} else {
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}

	return dp[i][j] = res;
}

int main() {
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>w[i]>>v[i];
	}
	cin>>W;
	memset(dp, -1, sizeof(dp));
	cout<<rec(0, W);
}