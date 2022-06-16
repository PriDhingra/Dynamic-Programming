int f(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp) {
    if(j < 0 || j >= a[0].size())
        return -1e8;
    
    if(i == 0)
        return a[0][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int up = a[i][j] + f(i - 1, j, a, dp);
    int lD = a[i][j] + f(i - 1, j - 1,a, dp);
    int rD = a[i][j] + f(i - 1, j + 1,a, dp);
    
    return dp[i][j] = max(up, max(lD, rD));
}


int getMaxPathSum(vector<vector<int>> &a)
{
    //  Write your code here.
    vector<vector<int>> dp(a.size(), vector<int>(a[0].size(), 0));
    
    for(int j = 0; j < a[0].size();j++) 
        dp[0][j] = a[0][j];
    
    for(int i = 1; i < a.size();i++) {
        for(int j = 0;j < a[0].size();j++) {
            int up = a[i][j] + dp[i - 1][j];
            int lD = a[i][j];
            if(j - 1 >= 0)
                lD += dp[i - 1][j - 1];
            else
                lD += -1e8;
            
            int rD = a[i][j];
            if(j + 1 <= a[0].size() - 1)
                rD += dp[i - 1][j + 1];
            else
                rD += -1e8;

            dp[i][j] = max(up, max(lD, rD));
        }
    }
    
    int maxi = -1e8;
    
    for(int j = 0;j < a[0].size();j++) 
        maxi = max(maxi, dp[a.size() - 1][j]);
    
    return maxi;
    
//     int maxi = -1e8;
//     for(int i = 0;i < a[0].size();i++) {
//         maxi = max(maxi, f(a.size() - 1, i, a, dp));
//     }
    
//     return maxi;
}
