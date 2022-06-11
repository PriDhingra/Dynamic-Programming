#include<bits/stdc++.h>
int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
    if(i > j) return 0;
    
    int mini = INT_MAX;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    for(int ind = i;ind <= j;ind++) {
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i, ind - 1, cuts, dp) + solve(ind + 1, j, cuts, dp);
        
        mini = min(mini, cost);
    }
    
    return dp[i][j] = mini;
}

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    
    sort(cuts.begin(), cuts.end());
    return solve(1, c, cuts, dp);
}
