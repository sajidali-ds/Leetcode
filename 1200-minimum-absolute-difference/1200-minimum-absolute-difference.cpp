class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int mini=INT_MAX;
        vector<vector<int>> result;
        for(int i=1;i<n;i++){
            int diff=arr[i]-arr[i-1];
            if(diff < mini){
                mini = diff;
                result.clear();

                result.push_back({arr[i-1], arr[i]});
            }
            else if(mini==diff){
                result.push_back({arr[i-1], arr[i]});   
            }
            
        }
        return result;
    }
};