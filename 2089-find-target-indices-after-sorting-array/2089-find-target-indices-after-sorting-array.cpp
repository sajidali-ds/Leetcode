class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        // TC-O(nlogn)
        
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
        return ans;
        
        //TC-O(n)
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i] < target){
        //         count++;
        //     }
        // }
        // vector<int> ans;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         ans.push_back(count);
        //         count++;
        //     }
        // }
        // return ans;
    }
};