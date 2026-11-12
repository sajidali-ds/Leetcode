class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result = *max_element(nums.begin(),nums.end());
        int sum=nums[0];
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]){
                sum +=nums[i];
                  
            }
            else{
                sum=nums[i];
            }
            result = max(result, sum);
        }
        return result;
        
    }
};