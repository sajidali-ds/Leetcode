class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int a = nums[n-1] - nums[2];// dono first ko min
        int b = nums[n-2] - nums[1];// 1 first ek last ko min
        int c = nums[n-3] - nums[0];//2 no last ko min
        return min({a,b,c});

    }
};