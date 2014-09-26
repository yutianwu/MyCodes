class Solution {
public:
    int minDistance(string word1, string word2) {
        const size_t len1 = word1.size();
        const size_t len2 = word2.size();

        int dp[len1 + ][len2 + 1];
        for (int i = 0; i <= len1; i++) {
        	dp[i][0] = i;
        }
        for (int j = 0; j <= len2; j++) {
        	dp[0][j] = j;
        }

        for (int i = 1; i <= len1; i++) {
        	for (int j = 1; j <= len2; j++) {
        		if (word1[i - 1] == word2[j - 1]) {
        			dp[i][j] = dp[i - 1[j - 1]];
        		} else {
        			int min = min(dp[i - 1][j], dp[i][j - 1]); //删除和插入，一个的删除反过来说就是在另一个上插入
        			dp[i][j] = 1 + min(dp[i - 1][j - 1], mn);  //替换
        		}
        	}
        }
        return dp[len1][len2];
    }
};