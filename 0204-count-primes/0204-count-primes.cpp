class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        vector<bool> isprime(n, true);
        isprime[0]=false;
        isprime[1]=false;
        int count=1;
        for(int i=3;i<=n/i;i+=2){
            if(isprime[i]){
                for(int j=i*i ;j<n;j+=2*i){
                   isprime[j]=false;
                }
            }
        }
        for(int i=3;i<n;i+=2){
            if(isprime[i]){
                count++;
            }
        }
        return count;
        
    }
    
};