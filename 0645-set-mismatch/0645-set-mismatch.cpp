class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int repeat=-1;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(i > 0 && nums[i] == nums[i-1]){
                repeat=nums[i];
            }
        }
        int actual_sum = n*(n+1)/2;

        int missing=actual_sum - sum + repeat;
        return {repeat,missing};
        
    }
};