int f(int ind, int tar, vector<int> &num, vector<vector<int>> &dp) {
    if(tar == 0)
        return 1;
    
    if(ind == 0) {
        if(num[ind] == tar)
            return 1;
        else
            return 0;
    }
    
    if(dp[ind][tar] != -1)
        return dp[ind][tar];
    
    int notTake = f(ind - 1, tar, num, dp);
    int take = 0;
    if(num[ind] <= tar)
        take = f(ind - 1, tar - num[ind], num, dp);
    
    return dp[ind][tar] = take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
//     return f(n - 1, tar, num, dp);
    
    for(int i = 0;i < n;i++)
        dp[i][0] = 1;
    
    if(num[0] <= tar)
        dp[0][num[0]] = 1;
    
    for(int ind = 1;ind < n;ind++) {
        for(int targ = 0;targ <= tar;targ++) {
            int notTake = dp[ind - 1][targ];
            int take = 0;
            if(num[ind] <= targ)
                take = dp[ind - 1][targ - num[ind]];

            dp[ind][targ] = take + notTake;
        }
    }
    
    return dp[n - 1][tar];
}
