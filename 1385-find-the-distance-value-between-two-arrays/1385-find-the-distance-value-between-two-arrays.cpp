class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();
        int ans=0;
        sort(begin(arr2),end(arr2));
        for(int i=0;i<n;i++){
            int low=0,high=m-1;
            bool flag=true;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(abs(arr1[i]-arr2[mid])<=d){
                    flag=false;
                    break;
                }else if(arr2[mid]<arr1[i]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
                
            }
            if(flag) ans++;
        }
        return ans;
    }
};