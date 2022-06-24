#include <bits/stdc++.h> 
int maximumProfit(vector<int> &p){
    // Write your code here.
    int mini = p[0];
    int profit = 0;
    int n = p.size();
    
    for(int i = 1;i < n;i++) {
        profit = max(profit, p[i] - mini);
        mini = min(mini, p[i]);
    }
    
    return profit;
}
