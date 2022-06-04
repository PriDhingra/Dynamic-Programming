class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        
        for(int i = 0;i < nums.size();i++)
            res = max(res, nums[i]);
        
        int curMin = 1;
        int curMax = 1;
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] == 0) {
                curMin = curMax = 1;
                continue;
            }
            
            int temp = curMax * nums[i];
            curMax = max(nums[i], max(nums[i] * curMax, nums[i] * curMin));
            curMin = min(nums[i], min(temp, nums[i] * curMin));
            
            res = max(res, curMax);
        }
        
        
        return res;
    }
};
