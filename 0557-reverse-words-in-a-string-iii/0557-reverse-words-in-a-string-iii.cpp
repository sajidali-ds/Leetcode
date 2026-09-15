class Solution {
public:
    void reverse(string& s,int start,int end){
        int left=start;
        int right=end;
        while(left < right){
            swap(s[left],s[right]);
            left++;
            right--;
            
        }
    }
    string reverseWords(string s) {
        int start=0;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
               reverse(s,start,i-1);
               start=i+1;
            } 
        }
        reverse(s,start,n-1);
        return s;
        
    }
};