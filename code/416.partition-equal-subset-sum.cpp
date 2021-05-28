class Solution {
public:    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int req_sum = sum / 2;
            
        if(sum%2 != 0 || *max_element(nums.begin(), nums.end()) > req_sum)
            return false;
        
        int m = nums.size();
        bool dp[m][req_sum+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=0; i<m; i++){
            dp[i][nums[i]] = true;
            dp[i][0] = true;
        }
        
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<=req_sum; j++){
                if(nums[i] > j)
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]];
            }
        }
        return dp[m-1][req_sum];
    }
};