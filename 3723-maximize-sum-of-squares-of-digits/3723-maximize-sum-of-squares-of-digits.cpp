class Solution {
public:
    
    
    
    string maxSumOfSquares(int num, int sum) {
        if(sum > num * 9){
            return {};
        }
        int nine=sum/9;
        int remainder=sum%9;
        string ans(nine,'9');
        if(remainder > 0){
            ans.push_back(remainder+'0');
        }
        ans.append(num-ans.length(),'0');
        return ans;

    }
};