//≤Â»Î≈≈–Ú
#include <iostream>
using namespace std;

void insertSort(int *a, int n) {
	for (int j=1; j<n; j++) {
		int key = a[j];
		int k = j-1;
		while(a[k] > key) {
			a[k+1] = a[k];
			k--;
		}
		a[k+1] = key;
	}
}

void main() {
	int origin[5] = {5,4,3,2,1};
	insertSort(origin, 5);
	for (int i=0; i<5; i++) {
		cout<<origin[i]<<endl;
	}
	system("PAUSE");

}