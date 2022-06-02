class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size();
        int size2 = text2.size();
        int dp[size1 + 1][size2 + 1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = size1 - 1;i >= 0;i--) {
            for(int j = size2 - 1;j >= 0;j--) {
                if(text1[i] == text2[j]) 
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else 
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        
        return dp[0][0];
    }
};
