class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int M=1e9+7;
        vector<int> prefix_sum(n,0);
        prefix_sum[0]=arr[0];
        for(int i=1;i<n;i++){
            prefix_sum[i] += prefix_sum[i-1]+arr[i];
        }
        int count=0;
        int even_count=1;
        int odd_count=0;
        for(int i=0;i<n;i++){
            if(prefix_sum[i]%2 ==0){
                count=(count+odd_count)%M;
                even_count++;
            }
            else{
                count=(count+even_count)%M;
                odd_count++;
            }
        }
        return count;
        
    }
};