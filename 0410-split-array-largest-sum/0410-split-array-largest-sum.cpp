class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=0;
        int high=0;
        for(int i=0;i<nums.size();i++){
           low=max(low,nums[i]);
           high +=nums[i];
        }
        while(low < high){
            int mid=low+(high-low)/2;
            int currentSum=0;
            int subarrays=1;
            for (int i = 0; i < nums.size(); i++) {

                if (currentSum + nums[i] <= mid) {
                    currentSum += nums[i];
                }
                else {
                    subarrays++;
                    currentSum = nums[i];
                }
            }
            if (subarrays <= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};