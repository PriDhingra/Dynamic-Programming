int f(int i, int j, vector<vector<int>>& a, vector<vector<int>> &dp) {
    if(i == a.size() - 1)
        return a[i][j];
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int down = a[i][j] + f(i + 1, j, a, dp);
    int diagonal = a[i][j] + f(i + 1,j + 1, a, dp);
    
    return dp[i][j] = min(down, diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n, -1));
    
    for(int i = 0;i < n;i++)
        dp[n - 1][i] = triangle[n - 1][i];
    
    for(int i = n - 2;i >= 0;i--) {
        for(int j = i;j >= 0;j--) {
            int down = triangle[i][j] + dp[i + 1][j];
            int diagonal = triangle[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
//     return f(0, 0, triangle, dp);
}
