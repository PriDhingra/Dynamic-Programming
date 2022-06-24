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


//Tabulation
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
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    
    for(int i = n - 1;i >= 0;i--) {
        for(int j = 0;j < 2;j++) {
            long profit = 0;
            if(j == 1) {
                profit = max(-v[i] + dp[i + 1][0], 
                            0 + dp[i + 1][1]);
            } else {
                profit = max(v[i] + dp[i + 1][1], 
                            0 + dp[i + 1][0]);
            }

            dp[i][j] = profit;
        }
    }
    return dp[0][1];
}
