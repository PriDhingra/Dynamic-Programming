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
