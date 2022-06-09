class Solution {
public:
    int solve(int amount, int index, vector<vector<int>> &dp, vector<int> coins) {
        if(amount == 0)
            return 1;
        
        if(index == coins.size() || amount < 0)
            return 0;
        
        if(dp[index][amount] != -1)
            return dp[index][amount];
        
        return dp[index][amount] = solve(amount - coins[index], index, dp, coins) + solve(amount, index + 1, dp, coins);
    }
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return solve(amount, 0, dp, coins);
    }
};
