#include<vector>
int f(int i, int j, string &p, string &t, vector<vector<int>> &dp) {
    if(i < 0 && j < 0)
        return 1;
    
    if(i < 0 && j >= 0)
        return false;
    
    if(j < 0) {
        for(int k = 0;k <= i;k++) {
            if(p[k] != '*')
                return 0;
            
            return 1;
        }
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(p[i] == t[j] || p[i] == '?') 
        return dp[i][j] = f(i - 1, j - 1, p, t, dp);
    
    if(p[i] == '*')
        return dp[i][j] = f(i, j - 1, p, t, dp) | f(i - 1, j, p, t, dp);
    
    return dp[i][j] = 0;
}

bool wildcardMatching(string p, string t)
{
   // Write your code here.
    int n = p.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    return f(n - 1, m - 1, p, t, dp);
}
