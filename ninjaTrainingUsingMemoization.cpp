int solve(int index, vector<vector<int>> &points, int selectedValue, 
         vector<vector<int>> &dp) {
    if(index == 0) {
        int maxi = 0;
        for(int i = 0;i < 3;i++) {
            if(i != selectedValue) 
                maxi = max(maxi, points[index][i]);
        }
        
        return maxi;
    }
    
    if(dp[index][selectedValue] != -1)
        return dp[index][selectedValue];
    
    int maxi = 0;
    for(int i = 0;i < 3;i++) {
        if(i != selectedValue) { 
            int result = points[index][i] + solve(index - 1, points, i, dp);
            maxi = max(maxi, result);
        }
    }
    
    return dp[index][selectedValue] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    
    return solve(n - 1, points, 3, dp);
}
