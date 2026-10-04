class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int start,vector<int>& candidates,int remaining,vector<int>& curr){
        if(remaining==0){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(candidates[i] > remaining)
               continue;
            curr.push_back(candidates[i]);
            solve(i,candidates,remaining - candidates[i],curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> curr;
        solve(0,candidates,target,curr);
        return ans;
        
    }
};