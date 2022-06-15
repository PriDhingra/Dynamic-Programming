//Memoization
#include<bits/stdc++.h>
bool isPalindrome(int i, int j, string s) {
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    
    return true;
}

int f(int i, int n, string &str, vector<int> &dp) {
    if(i == n)
        return 0;
    
    if(dp[i] != -1)
        return dp[i];
    
    int minCost = INT_MAX;
    for(int j = i;j < n;j++) {
        if(isPalindrome(i, j, str)) {
            int cost = 1 + f(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    
    return dp[i] = minCost;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n = str.length();
    vector<int> dp(n, -1);
    return f(0, n, str, dp) - 1;
}




//Tabulation

#include<bits/stdc++.h>
bool isPalindrome(int i, int j, string s) {
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    
    return true;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n = str.length();
    vector<int> dp(n + 1, -1);
    dp[n] = 0;
    
    for(int i = n - 1;i >= 0;i--) {
        int minCost = INT_MAX;
        for(int j = i;j < n;j++) {
            if(isPalindrome(i, j, str)) {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        
        dp[i] = minCost;
    }
    return dp[0] - 1;
}

