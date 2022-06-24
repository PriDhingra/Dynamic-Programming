int f(int ind, int n, int buy, vector<int> &p, vector<vector<int>> dp) {
    if(ind >= n)
        return 0;
    
    if(dp[ind][buy] != -1)
        return dp[ind][buy];
    
    if(buy) {
        return dp[ind][buy] = max(-p[ind] + f(ind + 1, n, 0, p, dp), 0 + f(ind + 1, n, 1, p, dp));
    }
    
    return dp[ind][buy] = max(p[ind] + f(ind + 2, n, 1, p, dp), 0 + f(ind + 1, n, 0, p, dp));
}

int stockProfit(vector<int> &p){
    // Write your code here.
    int n = p.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    
    for(int ind = n - 1;ind >= 0;ind--) {
        for(int buy = 0; buy <= 1;buy++) {
            if(buy) {
                dp[ind][buy] = max(-p[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            } else {    
                dp[ind][buy] = max(p[ind] + dp[ind + 2][1], 0 + dp[ind + 1][0]);
            }
        }
    }
    
    return dp[0][1];
}
