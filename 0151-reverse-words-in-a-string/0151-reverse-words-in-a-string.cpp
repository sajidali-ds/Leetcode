class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        string ans="";
        string temp="";
        while(i<n){
            while(i<n &&s[i]==' ')
                i++;
            temp="";

            while(i<n &&s[i]!=' '){
                temp +=s[i];
                i++;
            }
            if(!temp.empty()){
                if(ans.empty())
                    ans=temp;
                else
                    ans=temp+" "+ans;
            }
            
        }
        return ans;
    }
};