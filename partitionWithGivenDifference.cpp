int mod = 1000000007;
int f(int ind, int tar, vector<int> &num, vector<vector<int>> &dp) {
    
    if(ind == 0) {
        if(tar == 0 && num[ind] == 0) return 2;
        if(tar == 0 || tar == num[0]) return 1;
        return 0;
    }
    
    if(dp[ind][tar] != -1)
        return dp[ind][tar];
    
    int notTake = f(ind - 1, tar, num, dp);
    int take = 0;
    if(num[ind] <= tar)
        take = f(ind - 1, tar - num[ind], num, dp);
    
    return dp[ind][tar] = (take + notTake) % mod;
}

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f(n - 1, tar, num, dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totalSum = 0;
    for(auto i: arr)
        totalSum += i;
    
    if(totalSum - d < 0 || (totalSum - d) % 2 )
        return false;
    
    return findWays(arr, (totalSum - d) / 2);
}




int mod = 1000000007;

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if(num[0] == 0) 
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    
    if(num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;
    
    for(int ind = 1;ind < n;ind++) {
        for(int targ = 0;targ <= tar;targ++) {
            int notTake = dp[ind - 1][targ];
            int take = 0;
            if(num[ind] <= targ)
                take = dp[ind - 1][targ - num[ind]];

            dp[ind][targ] = (take + notTake) % mod;
        }
    }
    
    return dp[n - 1][tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totalSum = 0;
    for(auto i: arr)
        totalSum += i;
    
    if(totalSum - d < 0 || (totalSum - d) % 2 )
        return false;
    
    return findWays(arr, (totalSum - d) / 2);
}


