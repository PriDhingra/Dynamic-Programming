int f(int ind, int x, vector<int> &num, vector<vector<int>> dp) {    
    if(ind == 0) {
        if(x % num[0] == 0)
            return x / num[0];
        else
            return 1e9;
    }
    
    if(dp[ind][x] != -1)
        return dp[ind][x];
        
    int notTake = 0 + f(ind - 1, x, num, dp);
    int take = 1e9;
    if(num[ind] <= x)
        take = 1 + f(ind, x - num[ind], num, dp);
    
    return dp[ind][x] = min(notTake, take);
}

int minimumElements(vector<int> &num, int target)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    
    for(int T = 0;T <= target;T++) {
        if(T % num[0] == 0)
            dp[0][T] = T / num[0];
        else
            dp[0][T] = 1e9;
    }
    
    for(int ind = 1;ind < n;ind++) {
        for(int T = 0; T <= target;T++) {
            int notTake = 0 + dp[ind - 1][T];
            int take = 1e9;
            if(num[ind] <= T)
                take = 1 + dp[ind][T - num[ind]];

            dp[ind][T] = min(notTake, take);
        }
    }
    
//     int ans = f(n - 1, target, num, dp);
    int ans = dp[n - 1][target];
    if(ans >= 1e9)
        return -1;
    
    return ans;
    
    
}
