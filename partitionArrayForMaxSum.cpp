#include<bits/stdc++.h>

int f(int ind, int k, int n, vector<int> &num, vector<int> &dp) {
    
    if(ind == n) return 0;
    
    if(dp[ind] != -1) return dp[ind];
    
    int maxAns = INT_MIN;
    int len = 0;
    int maxi = INT_MIN;
    
    for(int j = ind;j < min(n, ind + k);j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = (len * maxi) + f(j + 1, k, n, num, dp);
        maxAns = max(maxAns, sum);
    }
    
    return dp[ind] = maxAns;
}

int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    int n = num.size();
    vector<int> dp(n + 1, -1);
    dp[n] = 0 ;
    
    for(int ind = n - 1;ind >= 0;ind--) {
        int maxAns = INT_MIN;
        int len = 0;
        int maxi = INT_MIN;

        for(int j = ind;j < min(n, ind + k);j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = (len * maxi) + dp[j + 1];
            maxAns = max(maxAns, sum);
        }

        dp[ind] = maxAns;
    }
    
    return dp[0];
//     return f(0, k, n, num, dp);
}
