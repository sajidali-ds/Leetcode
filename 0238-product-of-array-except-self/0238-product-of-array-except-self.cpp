class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(nums.size());
        int left=1;
        for(int i=0;i<nums.size();i++){
            ans[i] = left;
            left = left * nums[i];
        }
        int right=1;
        for(int j=n-1;j>=0;j--){
            ans[j] = ans[j] * right;
            right = right * nums[j];
        }
        
        return ans;
    }
};