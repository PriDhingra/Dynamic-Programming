int lcs(string &s1, string &s2){
	//	Write your code here.
    int n = s1.size();
    int m = s2.size();
    
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for(int i = 0;i <= n;i++) 
        dp[i][0] = 0;
    
    for(int i = 0;i <= m;i++) 
        dp[0][i] = 0;
    
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1;
                if(s1[i - 2] == s2[j - 2]) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
            } else {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    
    return ans;
}
