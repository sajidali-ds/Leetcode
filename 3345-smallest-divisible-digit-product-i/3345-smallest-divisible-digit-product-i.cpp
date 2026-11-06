class Solution {
public:
    int productofitsdigit(int n){
        int ans=1;
        while(n > 0){
            
            ans *= n%10;
            
            n /= 10;
            
        }
        return ans;
    }
    int smallestNumber(int n, int t) {
        int num=0;
        for(int i=n;i<=100;i++){
            if(productofitsdigit(i) % t ==0){
                return i;
            }
        }
        return -1;
    }
};