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

            dp[ind][targ] = (take + notTake);
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

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    countPartitions(n, target, arr);
}
