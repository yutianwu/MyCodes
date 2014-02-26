/*
汉诺塔问题

假设有A, B, C三根柱子，问题就是将A柱上的n个盘子移动到C柱上，规则是一次只能移动一个盘子，而且必须是小的盘子在大的盘子上

解决汉诺塔问题的经典方式是使用递归法，大致可以分为三步：
一，将A柱上的N-1个盘子借助C柱移动到B柱上
二，将A柱上的第N个盘子移动到C柱上
三，将B柱上的N-1个盘子借助A柱移动到C柱上
*/

#include <iostream>
using namespace std;

void hanoi(int n, char a, char b, char c) {
	if (n == 1) {
		cout<<"move	"<<a<<"	to	"<<c<<endl;
	} else {
		hanoi(n-1, a, c, b);
		cout<<"move	"<<a<<"	to	"<<c<<endl;
		hanoi(n-1, b, a, c);
	}
}

void main() {
	hanoi(3, 'A', 'B', 'C');
	system("PAUSE");
}