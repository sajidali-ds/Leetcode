class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            int and_=INT_MAX;
            for(int j=i;j<n;j++){
                mini=min(mini,nums[j]);
                and_ &=nums[j];
                if(mini==and_){
                    count++;
                }
            }
        }
        return count;
    }
};