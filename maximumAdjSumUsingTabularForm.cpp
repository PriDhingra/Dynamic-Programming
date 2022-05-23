int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
	int n = nums.size();
	vector<int> dp(n, -1);
	
	dp[0] = nums[0];
	int neg = 0;
	
	for(int i = 1;i < n;i++) {
		int left = nums[i];
		if(i > 1)
			left += dp[i - 2];
		
		int right = 0 + dp[i - 1];
		
		dp[i] = max(left, right);
	}
	
	return dp[n - 1];
}
