#include <iostream>
#include <vector>
using namespace std;

#define NIL    0
#define UPLEFT 1
#define LEFT   2
#define UP     3


void LCSLength(vector<char> &X, vector<char> &Y, vector<vector<int>> &b) {
	int m = (int) X.size();
	int n = (int) Y.size();

	//对c[i,j]进行初始化
	vector<vector<int>> c;
	vector<int> row;
	for (int i = 0; i <= n; i++) {
		row.push_back(NIL);
	}
	for (int j = 0; j <= m; j++) {
		c.push_back(row);
		b.push_back(row);
	}	

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i-1] == Y[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = UPLEFT;
			} else {
				if (c[i][j-1] > c[i-1][j]) {
					c[i][j] = c[i][j-1];
					b[i][j] = UP;
				} else {
					c[i][j] = c[i-1][j];
					b[i][j] = LEFT;
				}
			}
		}
	}

	cout << c[m][n] <<endl;
}

void printLCS (vector<char> &X, vector<vector<int>> &b, int i, int j) {
	if (i == 0 || j == 0) {
		return;
	}
	if (b[i][j] == UPLEFT) {
		printLCS(X, b, i-1, j-1);
		cout<<X[i-1]<<endl;
	} else if(b[i][j] == UP) {
		printLCS(X, b, i-1, j);
	} else {
		printLCS(X, b, i, j-1);
	}
}

void main() {
	vector<char> x;
	vector<char> y;
	x.push_back('A');
	x.push_back('B');
	x.push_back('C');
	x.push_back('B');
	x.push_back('D');
	x.push_back('A');
	x.push_back('B');

	y.push_back('B');
	y.push_back('D');
	y.push_back('C');
	y.push_back('A');
	y.push_back('B');
	y.push_back('A');

	vector<vector<int>> b;
	LCSLength(x, y, b);
	printLCS(x, b, x.size(), y.size());
	system("PAUSE");
}