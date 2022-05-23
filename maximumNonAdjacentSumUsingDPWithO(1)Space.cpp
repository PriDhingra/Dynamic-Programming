int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
	int n = nums.size();
	vector<int> dp(n, -1);
	int prev = nums[0];
	int prev2 = 0;
	dp[0] = nums[0];
	
	for(int i = 1;i < n;i++) {
		int left = nums[i];
		if(i > 1)
			left += prev2;
		
		int right = 0 + prev;
		
		int curr = max(left, right);
		
		prev2 = prev;
		prev = curr;
	}
	
	return prev;
}
