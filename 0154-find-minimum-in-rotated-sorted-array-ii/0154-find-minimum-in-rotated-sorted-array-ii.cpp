class Solution {
public:
    int findMin(vector<int>& nums) {
        // Linear Search - O(n)
        // int mini=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i] < mini){
        //         mini=nums[i];
        //     }
        // }
        // return mini;

        //Using Sorting-O(n log n)
        // sort(nums.begin(),nums.end());
        // return nums[0];

        //Binary Search - O(log n)

        int low=0;
        int high=nums.size()-1;
        while(low < high){
            int mid=low+(high - low)/2;
            if(nums[mid] > nums[high]){
                low=mid+1;
                
            }
            else if(nums[mid] < nums[high]){
                high = mid;
            }
            else{
                high--;
            }
        }
        return nums[low];
    }
};