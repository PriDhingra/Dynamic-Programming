class Solution {
private: 
    int f(int i, int j, string &t, string &s, vector<vector<int>> &dp) {
        if(j < 0)
            return 1;

        if(i < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(t[i] == s[j])
            return dp[i][j] = f(i - 1, j - 1, t, s, dp) + f(i - 1, j, t, s, dp);

        return dp[i][j] = f(i - 1, j, t, s, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        return f(n - 1, m - 1, s, t, dp);
    }
};
