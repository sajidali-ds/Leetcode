class Solution {
public:
    int minMoves(vector<int>& nums) {
        int larger= *max_element(nums.begin(),nums.end());
        int move=0;
        for(int i=0;i<nums.size();i++){
            move +=larger-nums[i];
        }
        return move;
    }
};