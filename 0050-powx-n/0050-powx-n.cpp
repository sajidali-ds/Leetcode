class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        long double base=x;
        if(N<0){
            base = 1.0L / base;
            N=-N;
        }
        double ans=1.0L;
        while(N>0){
            if(N%2==1){
                ans *= base;

            }
            base *= base;
            N /= 2;
        }
        return double(ans);
    }
};