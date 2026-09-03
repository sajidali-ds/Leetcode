class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i]=(nums1[i]-nums1[j]) || nums1[i];
                if(ans[i]%2==1 || ans[i]%2==0){
                    return true;
                }
            }

        }
        return false;
           
    }
};