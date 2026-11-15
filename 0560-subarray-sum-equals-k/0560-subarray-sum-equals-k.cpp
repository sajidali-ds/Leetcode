class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        // unordered_map<int,int> freq;
        // freq[0]=1;
        // long long sum=0;
        // int count=0;

        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     if(freq.count(sum-k))
        //        count+=freq[sum-k];
            
        //     freq[sum]++;

        // }
        // return count;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
};