bool comp(string &a, string &b) {
    return a.size() < b.size();
}

bool checkPossible(string &a, string &b) {
    if(a.size() != b.size() + 1)
        return false;
    
    int i = 0;
    int j = 0;
    
    while(i < a.size()) {
        if(j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    
    if(i == a.size() && j == b.size())
        return true;
    
    return false;
}

int longestStrChain(vector<string> &arr)
{
    // Write your code here.
    int n = arr.size();
    
    sort(arr.begin(), arr.end(), comp);
    vector<int> dp(n, 1);
    int maxi = 1;
    
    for(int i = 0;i < n;i++) {
        for(int prev = 0;prev < i;prev++) {
            if(checkPossible(arr[i], arr[prev]) && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
            }
        }
        if(dp[i] > maxi) {
            maxi = dp[i];
        }
    }
    
    return maxi;
}
