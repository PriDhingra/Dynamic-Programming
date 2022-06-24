int maximumProfit(int n, int fee, vector<int> &p) {
    // Write your code here.
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    
    for(int ind = n - 1;ind >= 0;ind--) {
        for(int buy = 0; buy <= 1;buy++) {
            if(buy) {
                dp[ind][buy] = max(-p[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            } else {    
                dp[ind][buy] = max(p[ind] - fee + dp[ind + 1][1], 0 + dp[ind + 1][0]);
            }
        }
    }
    
    return dp[0][1];
}
