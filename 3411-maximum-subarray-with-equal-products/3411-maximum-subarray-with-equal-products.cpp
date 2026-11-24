class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxlen=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            long long product=1;
            long long g=0;
            long long l=1;
            for(int j=i;j<n;j++){
                product *= nums[j];
                if (product > 2520LL * 10) break;
                g = gcd(g, (long long)nums[j]);

                l = (l / gcd(l, (long long)nums[j])) * nums[j];

                if(product == g*l){
                    maxlen=max(maxlen,j-i+1);
                }
            }
        }
        return maxlen;
    }
};