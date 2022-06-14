
int mod = 1000000007;

long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp) {
    if(i > j) return 0;
    
    if(i == j) {
        if(isTrue) 
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }
    
    if(dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    
    long long ways = 0;
    
    for(int ind = i + 1;ind <= j - 1;ind += 2) {
        long long lT = f(i, ind - 1, 1, exp, dp);
        long long lF = f(i, ind - 1, 0, exp, dp);
        long long rT = f(ind + 1, j, 1, exp, dp);
        long long rF = f(ind + 1, j, 0, exp, dp);
        
        if(exp[ind] == '&') {
            if(isTrue) ways = (ways + (rT * lT) % mod) % mod;
            else ways = (ways + (rT * lF) % mod + (rF * lT) % mod + (rF * lF) % mod) % mod;
        } else if(exp[ind] == '|') {
            if(isTrue) ways = (ways + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        } else {
            if(isTrue) ways = (ways + (lT * rF) % mod + (lF * rT) % mod) % mod;
            else ways = (ways + (lT * rT) % mod + (lF * rF) % mod) % mod; 
        }
    }
    
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return f(0, exp.size() - 1, 1, exp, dp);
}
