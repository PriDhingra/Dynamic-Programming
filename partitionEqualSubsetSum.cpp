class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++) 
            sum += nums[i];
        
        if(sum % 2) 
            return  false;
        
        set<int> dp;
        dp.insert(0);
        
        int target = sum / 2;
        for(int i = nums.size() - 1;i >= 0;i--) {
            set<int> nextDp;
            for(auto j: dp) {
                nextDp.insert(j + nums[i]);
                nextDp.insert(j);
            }
            dp = nextDp;
        }
        
        if(dp.find(target) != dp.end())
            return true;
        else
            return false;
    }
};
