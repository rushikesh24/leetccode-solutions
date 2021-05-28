class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> u_map;
        for(auto num : nums1){
            u_map[num] += 1;
        }
        
        vector<int> res;
        for(auto num : nums2){
            if(u_map.find(num) != u_map.end() && u_map[num]){
                u_map[num]--;             
                res.push_back(num);
            }
        }
        return res;
    }
};