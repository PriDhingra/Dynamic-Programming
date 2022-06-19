int f(int ind, int n, vector<int> &pr, vector<vector<int>> &dp) {
    if(ind == 0)
        return n * pr[0];
    
    if(dp[ind][n] != -1)
        return dp[ind][n];
    
    int notTake = 0 + f(ind - 1, n, pr, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if(rodLength <= n)
        take = pr[ind] + f(ind, n - rodLength, pr, dp);
    
    return dp[ind][n] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, n, price, dp);
}
