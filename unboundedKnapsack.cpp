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


//Tabulation

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    
    for(int W = 0;W <= w;W++) {
        dp[0][W] = W / weight[0] * profit[0];
    }
    
    for(int ind = 1;ind < n;ind++) {
        for(int W = 0;W <= w;W++) {
            int notTake = 0 + dp[ind - 1][W];
            int take = -1e8;
            if(weight[ind] <= W)
                take = profit[ind] + dp[ind][W - weight[ind]];

            dp[ind][W] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
//     return f(n - 1, w, profit, weight, dp);
}

