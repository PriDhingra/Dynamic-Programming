class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 1));
        
        for(int i = coins.size() - 1;i >= 0;i--) {
            for(int j = 1;j <= amount;j++) {
                if(i + 1 < coins.size())
                    dp[i][j] = dp[i + 1][j];
                else
                    dp[i][j] = 0;
                
                if(j - coins[i] >= 0)
                    dp[i][j] += dp[i][j - coins[i]];
            }
        }
        
        return dp[0][amount];
    }
};
