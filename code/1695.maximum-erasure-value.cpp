class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int len = nums.size();
        
        int sum = 0;
        int opt = INT_MIN;
        set<int> visited;
        while(right<len){
            if(visited.find(nums[right]) != visited.end()){
                while(nums[left] != nums[right]){
                    sum -= nums[left];
                    visited.erase(nums[left++]);
                }
                sum -= nums[left];
                visited.erase(nums[left++]);
            }   
            visited.insert(nums[right]);
            sum += nums[right];
            opt = max(opt, sum);
            // cout<<sum<<" "<<opt<<" "<<endl;
            right++;
        }
        return opt;
    }
};