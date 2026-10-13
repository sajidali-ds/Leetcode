class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=nums[i]*nums[i];
        }
        sort(ans.begin(),ans.end());
        long long sum1=0;
        for(int j=0;j<ans.size()/2;j++){
           sum1+=ans[j];
        }
        long long sum2=0;
        for(int k=ans.size()/2;k<ans.size();k++){
            sum2+=ans[k];
        }

        return sum2-sum1;
        
    }
};