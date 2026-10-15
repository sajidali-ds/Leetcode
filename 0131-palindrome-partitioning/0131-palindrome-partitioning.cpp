class Solution {
public:
    bool ispalindrome(string s,int left,int right){
        while(left < right){
            if(s[left++] != s[right--])  return false;
        }
        return  true;
    }
   
   
   void solve(int index ,const string& s,vector<string>& path, vector<vector<string>>& ans){
        if (index == s.size()) {    
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            
            if(ispalindrome(s,index,i)){
                path.push_back(s.substr(index, i - index + 1));
                solve(i + 1, s, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0, s, path, ans);
        return ans;
    }
};