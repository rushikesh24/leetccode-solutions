class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = nums.size()-1;
        while(zero >= 0 && !nums[zero]) zero--;
        
        for(int i=0; i<=zero; i++){
            if(!nums[i]){
                nums.push_back(0);
                nums.erase(nums.begin()+i);
                i--;
                cout<<i<<" "<<endl;
                zero--;
            }
        }
    }
};