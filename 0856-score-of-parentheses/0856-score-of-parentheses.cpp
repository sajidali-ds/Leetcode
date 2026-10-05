class Solution {
public:
    // int solve(string& s, int& i) {          
    //     int total = 0;
    //     while (i < s.size() && s[i] == '(') {
    //         i++;                          
    //         int inner = solve(s, i);
    //         i++;                       
    //         total += max(2 * inner, 1);
    //     }
    // return total;
    // }
    int scoreOfParentheses(string s) {
        int score=0;
        int depth =0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth++;
            }
            else if (s[i]==')'){
                depth--;
                if(s[i-1]=='('){
                    score += 1 << depth;
                }
            }
            
        }
        return score;
    
    

    
    
    
    //    int i=0;
    //    return solve(s,i);    
    }
};