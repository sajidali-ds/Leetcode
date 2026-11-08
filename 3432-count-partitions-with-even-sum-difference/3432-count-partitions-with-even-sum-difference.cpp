class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int count=0;
        int sum=0;
        int leftsum=0;
        int rightsum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
         
        }
        for(int j=0;j<nums.size()-1;j++){
            leftsum +=nums[j];
            rightsum=sum-leftsum;
            if((leftsum - rightsum)%2==0){
                count++;
            }
        }
        return count;
    }
};