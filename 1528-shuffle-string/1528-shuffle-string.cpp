class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        string ans=s;
        for(int j=0;j<s.size();j++){
            ans[indices[j]]=s[j];
        }
        
        return ans;
    }
};