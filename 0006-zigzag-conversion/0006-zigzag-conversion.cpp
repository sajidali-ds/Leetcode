class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }
        vector<string> rows(numRows);

        int i=0;
        while(i < s.size()){
            for(int row=0;row<numRows && i<s.size();row++){
               rows[row] += s[i++];
            }
            for (int row = numRows - 2; row > 0 && i < s.size(); row--) {
                rows[row] += s[i++];
            }
        }
        string ans = "";

        for (string row : rows) {
            ans += row;
        }

        return ans;

    }
};