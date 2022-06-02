class Solution {
public:
    int solve(int n, vector<int> &dp) {
        if(n < 0)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    }
    
    int climbStairs(int n) {
        int index = 0;
        vector<int> dp(n + 1, -1);
        dp[0] = 1;
        solve(n, dp);
        
        return dp[n];
    }
};
