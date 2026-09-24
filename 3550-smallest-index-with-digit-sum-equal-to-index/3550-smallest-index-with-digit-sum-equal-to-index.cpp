class Solution {
public:
    int sumdigit(int n){
        int sum=0;
        while(n>0){
            
            int digit=n%10;
            sum+=digit;
            n=n/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
      
        for(int i=0;i<nums.size();i++){
            if(i==sumdigit(nums[i]))
              return i;
        }
        return -1;
    }
   
};