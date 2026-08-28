class Solution {
public:
    bool check(string s){
        int n=s.size();
        int left=0;
        int right=n-1;
        while(left < right){
            if(s[left]!=s[right])
               return false;
            left++;
            right--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                string sub = s.substr(i, j - i + 1);
                if(check(sub))
                   count++;
            }
        }
        return count;
    }
};