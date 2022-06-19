int f(int ind, int W, vector<int> &pr, vector<int> &wt, vector<vector<int>> &dp) {
    if(ind == 0) {
        return (W / wt[0]) * pr[0];
    }
    
    if(dp[ind][W] != -1)
        return dp[ind][W];
    
    int notTake = 0 + f(ind - 1, W, pr, wt, dp);
    int take = -1e8;
    if(wt[ind] <= W)
        take = pr[ind] + f(ind, W - wt[ind], pr, wt, dp);
    
    return dp[ind][W] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, profit, weight, dp);
}
