//Memoization
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


//BottomUp
class Solution {
public:
    int climbStairs(int n) {
        int index = 0;
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        
        for(int i = n - 1;i >= 0;i--) {
            dp[i] += dp[i + 1];
            if(i + 2 <= n)
                dp[i] += dp[i + 2];
        }
        
        return dp[0];
    }
};
