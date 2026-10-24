class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int read = 0, write = 0, n = nums.size();
        while(read < n){
            if(nums[read] != 0){
                nums[write++] = nums[read];
            }
            read++;
        }

        while(write < n){
            nums[write++] = 0;
        }
    

        
    }

};