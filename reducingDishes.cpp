class Solution {
public:
    int solve(vector<int>& s, int index, int time) {
        if(index == s.size())
            return 0;
        
        int include = (time + 1) * s[index] + solve(s, index + 1, time + 1);
        int exclude = 0 + solve(s, index + 1, time);
        
        return max(include, exclude);
    }
    
    
    
    //Memoization
    int solveMem(vector<int>& s, int index, int time, vector<vector<int>> &dp) {
        if(index == s.size())
            return 0;
        
        if(dp[index][time] != -1)
            return dp[index][time];
        
        int include = (time + 1) * s[index] + solveMem(s, index + 1, time + 1, dp);
        int exclude = 0 + solveMem(s, index + 1, time, dp);
        
        return dp[index][time] = max(include, exclude);
    }
    
    
    
    //Tabulation
    int solveTab(vector<int>& s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int index = n - 1; index >= 0;index--) {
            for(int time = index; time >= 0;time--) {
                int include = (time + 1) * s[index] + dp[index + 1][time + 1];
                int exclude = 0 + dp[index + 1][time];
        
                dp[index][time] = max(include, exclude);
            }
        }
        
        return dp[0][0];
    }
    
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(), s.end());
        // int n = s.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveMem(s, 0, 0, dp);
        
        return solveTab(s);
    }
};
