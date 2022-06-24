//Runtime Error
#include<vector>
int f(int ind, int prev, int n, int arr[], vector<vector<int>> &dp) {
    if(ind == n)
        return 0;
    
    if(dp[ind][prev + 1] != -1) 
        return dp[ind][prev + 1];
    
    int len = 0 + f(ind + 1, prev, n, arr, dp);
    
    if(prev == -1 || arr[ind] > arr[prev]) 
        len = max(len, 1 + f(ind + 1, ind, n, arr, dp));
    
    return dp[ind][prev + 1] = len;
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, n, arr, dp);
}
