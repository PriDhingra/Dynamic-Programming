class Solution {
public:
//     int solve(int startIdx, int endIdx, vector<int>& s, int n, vector<vector<int>> dp) {
//         if(n == 0 || startIdx > endIdx)
//             return 0;
        
//         if(dp[startIdx][n] != -1)
//             return dp[startIdx][n];
        
//         int take = s[startIdx] + solve(startIdx + 2, endIdx, s, n - 1, dp);
//         int notTake = 0 + solve(startIdx + 1, endIdx, s, n, dp);
            
//         return dp[startIdx][n] = max(take, notTake);
//     }
    
    int maxSizeSlices(vector<int>& s) {
        int k = s.size();
        vector<vector<int>> dp1(k + 2, vector<int>(k + 2, 0));
        vector<vector<int>> dp2(k + 2, vector<int>(k + 2, 0));
        // int case1 = solve(0, k - 2, s, k/3, dp1);
        // int case2 = solve(1, k - 1, s, k/3, dp2);
        
        for(int startIdx = k - 2;startIdx >= 0; startIdx--) {
            for(int n = 1;n <= k / 3;n++) {
                int take = s[startIdx] + dp1[startIdx + 2][n - 1];
                int notTake = 0 + dp1[startIdx + 1][n];
            
                dp1[startIdx][n] = max(take, notTake);
            }
        }
        
        for(int startIdx = k - 1;startIdx >= 1; startIdx--) {
            for(int n = 1;n <= k / 3;n++) {
                int take = s[startIdx] + dp2[startIdx + 2][n - 1];
                int notTake = 0 + dp2[startIdx + 1][n];
            
                dp2[startIdx][n] = max(take, notTake);
            }
        }
        
        return max(dp1[0][k/3], dp2[1][k/3]);
    }
};
