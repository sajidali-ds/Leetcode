class Solution {
public:
   

    int singleNumber(vector<int>& nums) {
        
        int result=0;
        for(int k=0;k<32;k++){
            int countone=0;
            int temp = (1 << k);

            for(int i=0;i<nums.size();i++){
                if((nums[i] & temp) != 0){
                    countone++;
                }
                
            }
            if(countone %3 ==1){
               result=(result | temp);
            }
            
        }
        return result;
    }
};