class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> u_map;
        for(auto num : nums1){
            u_map[num] = 1;
        }
        set<int> res;
        
        for(auto num : nums2){
            if(u_map.find(num) != u_map.end())
                res.insert(num);
        }
        vector<int> re(res.begin(), res.end());
        return re;
    }
};