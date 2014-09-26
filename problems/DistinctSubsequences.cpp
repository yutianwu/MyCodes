class Solution {
public:
	string s;
	string t;
	int len_s;
	int len_t;

    int numDistinct(string S, string T) {
		vector<int> dp(T.size() + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < S.size(); i++) {
			for (int j = T.size() - 1; j >= 0; j--) {
				dp[j + 1] += S[i] == T[j] ? dp[j] : 0;
			}
		}		    
		return dp[T.size()];
	}


    int numDistinct1(string S, string T) {
        s = S;
        t = T;
        len_s = s.size();
        len_t = t.size();

        if (len_s == 0 || len_t == 0) {
        	return 0;
        }

        return rec(0, 0);
    }

    //i for pointer of T, j for pointer of S 
    int rec(int i, int j) {
    	int res = 0;
    	if (i == len_t) {
    		res = 1;
    	} else if (j == len_s) {
    		res = 0;
    	} else if (t[i] == s[j]) {
    		res = rec(i + 1, j + 1) + rec(i, j + 1);
    	} else {
    		res = rec(i, j + 1);
    	}
    	return res;
    }
};