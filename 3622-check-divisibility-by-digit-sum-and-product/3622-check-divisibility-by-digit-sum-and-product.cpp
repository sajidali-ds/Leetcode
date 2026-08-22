class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int original_num=n;
        while(n>0){
            int digit=n%10;
            sum+=digit;
            product *= digit;
            
            n/=10;

        }
        int overall_sum=(sum+product);
        return (original_num % overall_sum == 0);
    }
};