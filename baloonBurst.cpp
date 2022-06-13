class Solution {
public:
    //int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
      //  if(i > j)
        //    return 0;
        
        //if(dp[i][j] != -1)
          //  return dp[i][j];
        
      //  int maxi = INT_MIN;
        //for(int k = i; k <= j;k++) {
          //  int coins = nums[i - 1] * nums[k] * nums[j + 1];
            //coins += solve(i, k - 1, nums, dp) + solve(k + 1, j, nums, dp);
            
            //maxi = max(maxi, coins);
        //}
        
        //return dp[i][j] = maxi;
    //}
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0)); 
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        for(int i = n; i >= 1;i--) {
            for(int j = 1;j <= n;j++) {
                if(i > j) continue;
                
                int maxi = INT_MIN;
                for(int k = i; k <= j;k++) {
                    int coins = nums[i - 1] * nums[k] * nums[j + 1];
                    coins += dp[i][k - 1] + dp[k + 1][j];

                    maxi = max(maxi, coins);
                }

                dp[i][j] = maxi;
            }
        }
        
        return dp[1][n];
        // return solve(1, n, nums, dp);
    }
};
