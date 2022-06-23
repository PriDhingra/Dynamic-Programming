#include<vector>
long f(int i, int buy, long *v, int n, vector<vector<long>> &dp) {
    if(i == n)
        return 0;
    
    if(dp[i][buy] != -1)
        return dp[i][buy];
    
    long profit = 0;
    if(buy) {
        profit = max(-v[i] + f(i + 1, 0, v, n, dp), 
                    0 + f(i + 1, 1, v, n, dp));
    } else {
        profit = max(v[i] + f(i + 1, 1, v, n, dp), 
                    0 + f(i + 1, 0, v, n, dp));
    }
    
    return dp[i][buy] = profit;
}

long getMaximumProfit(long *v, int n)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return f(0, 1, v, n, dp);
}
