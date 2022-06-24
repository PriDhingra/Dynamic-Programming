int f(int i, int n, int buy, int cap, vector<int>& p, vector<vector<vector<int>>> &dp) {
    if(i == n || cap == 0)
        return 0;
    
    if(dp[i][buy][cap] != -1)
        return dp[i][buy][cap];
    
    if(buy) {
        return dp[i][buy][cap] =  max(-p[i] + f(i + 1, n, 0, cap, p, dp),
                    0 + f(i + 1, n, 1, cap, p, dp));
    } 
    
    return dp[i][buy][cap] = max(p[i] + f(i + 1, n, 1, cap - 1, p, dp),
                    0 + f(i + 1, n, 0, cap, p, dp));

}

int maxProfit(vector<int>& p, int n)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, n, 1, 2, p, dp);
}



int maxProfit(vector<int>& p, int n)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    
    for(int i = n - 1;i >= 0;i--) {
        for(int buy = 0;buy <= 1;buy++) {
            for(int cap = 1;cap <= 2;cap++) {
                if(buy == 1) {
                    dp[i][buy][cap] =  max(-p[i] + dp[i + 1][0][cap], 0 + dp[i + 1][1][cap]);
                } else {
                    dp[i][buy][cap] = max(p[i] + dp[i + 1][1][cap - 1], 0 + dp[i + 1][0][cap]);
                }
            }
        }
    }
    
    return dp[0][1][2];
}
