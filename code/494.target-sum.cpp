class Solution {
public:
    int count = 0;
    bool solve(vector<int>& nums, int target, int curr_sum, int index){
        if(curr_sum == target && index == nums.size()){
            count++;
            return true;
        }
        int i = index;
        // cout<<i<<"\t"<<curr_sum<<endl;
        if(i>=nums.size()) return false;
        // for(int i=index; i<nums.size(); i++){
            solve(nums, target, curr_sum+nums[i], i+1);
            solve(nums, target, curr_sum-nums[i], i+1);
        // }        
        return false;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums, target, 0, 0);
        return count;
    }
};