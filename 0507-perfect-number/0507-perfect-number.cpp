class Solution {
public:
    bool checkPerfectNumber(int num) {
        int original=num;
        
        int digitsum=0;
        for(int i=1;i < num;i++){
            if(num % i ==0){
                digitsum+=i;
            }
        }

        if(digitsum == original)
           return true;
        else
           return false;
    }
};