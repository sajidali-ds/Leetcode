class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=abs(nums[i]);
            int idx=num-1;

            if(nums[idx] < 0){
                ans= num;
            }
            else{
                nums[idx] *= -1;
            }
        }
        return ans;
        
    }
};