class Solution {
public:

    bool check(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
               return false;
            }
            
            i++;
            j--;
            
        }
        return true;
    }
       
    string longestPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        int maxLen=1;
        int start=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(check(s,i,j)){
                    int len=j-i+1;

                    if(len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
        
    }
};