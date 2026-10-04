class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i] == '*'){
               count++;
            }
            else{
               count--;
            }
            if(count < 0) {
                return false;
            }
        }
        count=0;
        for(int i=n-1;i >=0 ;i--){
            if(s[i]==')' || s[i]=='*'){
                count++;
            }
            else{
                count--;
            }
            if(count < 0){
                return false;
            }
        }
        
        return true;
        

    }
};