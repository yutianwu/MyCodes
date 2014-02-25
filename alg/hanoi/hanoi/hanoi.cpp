/*
��ŵ������

������A, B, C�������ӣ�������ǽ�A���ϵ�n�������ƶ���C���ϣ�������һ��ֻ���ƶ�һ�����ӣ����ұ�����С�������ڴ��������

�����ŵ������ľ��䷽ʽ��ʹ�õݹ鷨�����¿��Է�Ϊ������
һ����A���ϵ�N-1�����ӽ���C���ƶ���B����
������A���ϵĵ�N�������ƶ���C����
������B���ϵ�N-1�����ӽ���A���ƶ���C����
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