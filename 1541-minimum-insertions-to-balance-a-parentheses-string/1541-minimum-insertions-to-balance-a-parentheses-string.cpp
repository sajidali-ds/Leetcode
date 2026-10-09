class Solution {
public:
    
    int minInsertions(string s) {
        int add=0;
        int need=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(need % 2 ==1){
                    add++;
                    need--;
                }
                
                need +=2;
            
            }
             
            else{
                need--;
                if(need < 0){
                    add++;
                    need+=2;
                }
            }
               
        }
        return add+need;
    }
};