class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxindexreach=0;
        for(int i=0;i<nums.size();i++){
            if(i > maxindexreach){
                return false;
            }
            maxindexreach = max(maxindexreach, i+ nums[i]);
        }
        return true;
    }
};