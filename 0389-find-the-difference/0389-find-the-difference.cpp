class Solution {
public:
    char findTheDifference(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // int i=0;
        // int n=s.size();

        // while(i < n){
        //     if(s[i]!=t[i]){
        //         return t[i];
        //     }
        //     i++;
        // }
        // return t[n];

        // Optimal solution

        int result=0;
        for(char c:s){
            result ^=c;
        }
        for(char c:t){
            result ^=c;
        }
        return result;
    }
};