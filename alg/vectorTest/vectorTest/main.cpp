#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int>> permutions;
        perm(permutions, num, 0);
        return permutions; 
    }
    
    void swap(int *m, int *n) {
        int tmp = *m;
        *m = *n;
        *n = tmp;
    }
    
    void perm(vector<vector<int>> &permutions, vector<int> &num, int k) {
        if (k == num.size()) {
            permutions.push_back(num);
			for(vector<int>::size_type i=0; i < num.size(); i++) {
				cout<<num[i]<<"\t";
			}
			cout<<endl;
        } else {
            for (vector<int>::size_type j = k; j < num.size(); j++) {
                swap(&num[k], &num[j]);
                perm(permutions,num, j);
                swap(&num[k], &num[j]);
            }
        }
    }
};

void main() {
	Solution so;
	vector<int> vec(3,1);
	vec[1] = 2;
	vec[2] = 3;

	so.permute(vec);
	system("PAUSE");
}