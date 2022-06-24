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





//using binary search TC O(n) and SC O(n)

#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> temp;
    temp.push_back(arr[0]);
    int len = 1;
    
    for(int i = 1;i < n;i++) {
        if(arr[i] > temp.back()) {
            temp.push_back(arr[i]);
            len++;
        }
        else {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    
    return len;
}

