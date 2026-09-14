class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(!isSorted(nums)){
            int minIndex = 0;
        
            for(int i = 1; i < nums.size() - 1; i++) {
                if(nums[i] + nums[i + 1] <
                    nums[minIndex] + nums[minIndex + 1]) {
                    minIndex = i;
                }
                
            }
            nums[minIndex] = nums[minIndex] + nums[minIndex + 1];
            nums.erase(nums.begin() + minIndex + 1);
            count++;
        }
        return count;

    }
};