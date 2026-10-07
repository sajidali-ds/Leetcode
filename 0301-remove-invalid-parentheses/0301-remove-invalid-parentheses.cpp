class Solution {
public:
    
 
    set<string> st;
    void solve(string& s, int idx, int l, int r, int open, string& cur) {
        if(idx==s.size()){
            if (l == 0 && r == 0 && open == 0)
                st.insert(cur);
            return;
        }
        char ch = s[idx];

        if (ch == '(' && l > 0)
            solve(s, idx + 1, l - 1, r, open, cur);
        else if (ch == ')' && r > 0)
            solve(s, idx + 1, l, r - 1, open, cur);
        cur.push_back(ch);
        if (ch == '(')
            solve(s, idx + 1, l, r, open + 1, cur);
        else if (ch == ')') {
            if (open > 0)            
                solve(s, idx + 1, l, r, open - 1, cur);
        }
        else
            solve(s, idx + 1, l, r, open, cur);
        cur.pop_back();                        
    }
     
    vector<string> removeInvalidParentheses(string s) {
       int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') l++;
            else if (s[i] == ')') {
                if (l > 0) l--;
                else r++;
            }
        }
        string cur = "";
        solve(s, 0, l, r, 0, cur);
        return vector<string>(st.begin(), st.end());
    }
};