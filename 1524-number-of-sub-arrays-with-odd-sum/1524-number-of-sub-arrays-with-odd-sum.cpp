class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int M=1e9+7;
        int count=0;
        int sum=0;
        int even_count=1;
        int odd_count=0;
        for(int i=0;i<n;i++){
            sum+= arr[i];
             if(sum%2 ==0){
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