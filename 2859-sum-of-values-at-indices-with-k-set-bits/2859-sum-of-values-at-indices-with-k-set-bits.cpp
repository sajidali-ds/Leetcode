class Solution {
public:
    int countsetbits(int n){
        int count=0;
        while(n > 0){
            count +=(n&1);
            n=n >>1;
        }
        return count;
    }

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(countsetbits(i)==k){
                sum+= nums[i];
            }
        }
        return sum;
    }
};