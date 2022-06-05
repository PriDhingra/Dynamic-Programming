class Solution {
public:
    int solve(int d, vector<int> &days, vector<int> &cost, vector<int> &dp) {
        if(d >= days.size())
            return 0;
        
        if(dp[d] != -1)
            return dp[d];
        
        int oneDayPass = solve(d + 1, days, cost, dp) + cost[0];
        
        int i;
        for(i = d;i < days.size();i++) {
            if(days[i] >= days[d] + 7)
                break;
        }
        
        int sevenDayPass = solve(i, days, cost, dp) + cost[1];
        
        for(i = d;i < days.size();i++) {
            if(days[i] >= days[d] + 30)
                break;
        }
        
        int thirtyDayPass = solve(i, days, cost, dp) + cost[2];
        
        return dp[d] = min(oneDayPass, min(sevenDayPass, thirtyDayPass));
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(0, days, costs, dp);
    }
};
