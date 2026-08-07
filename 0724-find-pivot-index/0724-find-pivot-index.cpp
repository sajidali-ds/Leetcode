class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int Total_sum=0;
        for(int i=0;i<nums.size();i++){
            Total_sum+=nums[i];
            
        }
        int left_sum=0;
        for(int i=0;i<nums.size();i++){
            
            int right_sum=Total_sum - left_sum - nums[i];
            if(left_sum==right_sum){
                return i;
            }
            left_sum+=nums[i];
        }
        return -1;
    }
};