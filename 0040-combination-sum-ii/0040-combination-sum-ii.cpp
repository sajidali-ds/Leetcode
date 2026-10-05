class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start,int remaining,vector<int>& candidates,vector<int>curr){
        if(remaining==0){
            ans.push_back(curr);
            return;
        }
        
        for(int i=start;i<candidates.size();i++){
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            if(candidates[i] > remaining)
               break;
            curr.push_back(candidates[i]);
            solve(i+1,remaining - candidates[i],candidates,curr);
            curr.pop_back();
        }
       
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        solve(0,target,candidates,curr);
        return ans;
    }
};