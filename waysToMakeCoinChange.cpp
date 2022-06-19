#include<vector>
long f(int ind, int t, int *a, vector<vector<long>> &dp) {
    if(ind == 0)
        return (t % a[0] == 0);
    
    if(dp[ind][t] != -1)
        return dp[ind][t];
    
    long notTake = f(ind - 1, t, a, dp);
    long take = 0;
    if(a[ind] <= t)
        take = f(ind, t - a[ind], a, dp);
    
    return dp[ind][t] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return f(n - 1, value, denominations, dp);
}
