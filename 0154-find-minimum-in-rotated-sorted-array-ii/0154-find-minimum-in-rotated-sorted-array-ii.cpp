class Solution {
public:
    int findMin(vector<int>& nums) {
        // Linear Search - O(n)
        // int mini=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i] < mini){
        //         mini=nums[i];
        //     }
        // }
        // return mini;
        sort(nums.begin(),nums.end());
        return nums[0];

        //Binary Search - O(log n)
        
    }
};