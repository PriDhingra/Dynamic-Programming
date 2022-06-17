int f(int n, int x, int y, int z, vector<int> &dp) {
    if(n == 0)
        return 0;
    
    if(n < 0)
        return -1e8;
    
    if(dp[n] != -1)
        return dp[n];
    
    int a = f(n - x, x, y, z, dp) + 1;
    int b = f(n - y, x, y, z, dp) + 1;
    int c = f(n - z, x, y, z, dp) + 1;
        
    return dp[n] = max(a, max(b, c));
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
    vector<int> dp(n + 1, -1e8);    
    int ans =  f(n, x, y, z, dp);
    dp[0] = 0;
    
    for(int i = 1;i <= n;i++) {
        if(i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);
        
        if(i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);
        
        if(i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }
    
    if(dp[n] < 0)
        return 0;
    else
        return dp[n];
    
//     if(ans < 0)
//         return 0;
//     else
//         return ans;
}
