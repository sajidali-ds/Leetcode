class Solution {
public:
    bool rotateString(string s, string goal) {
        
        if(s.length() != goal.length())
            return false;
            
        string doubled = s+s;
        int n=goal.length();
        for(int i=0;i<=doubled.length()-n;i++){
            int j=0;
            while(j<n && doubled[i+j]==goal[j]){
                j++;
            }
            if(j==n)
               return true;
        }
        return false;
    }
};