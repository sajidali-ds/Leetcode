class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newinterval) {
        int i=0;
        vector<vector<int>> result;
        int n=intervals.size();
        while(i < n){
            if(intervals[i][1] < newinterval[0]){
                result.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newinterval[1]){
                break;
            }
            else{
                newinterval[0]=min(intervals[i][0],newinterval[0]);
                newinterval[1]=max(intervals[i][1],newinterval[1]);
                
            }
            i++;
        }
        result.push_back(newinterval);
        while(i<n){
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};