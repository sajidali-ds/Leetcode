class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans=0;
        if(k==0){
            ans= numOnes;
        }
        
            
        if(k > (numOnes + numZeros)){
            ans=  numOnes-(k-(numOnes+numZeros));
        }
        if(k > numOnes && k< (numOnes+numZeros)){
            ans=numOnes;
        }
        if(k == (numOnes + numZeros + numNegOnes)){
            ans=numOnes - numNegOnes;
        }
        if(k==(numOnes) + numZeros){
            ans=numOnes;
        }
        
        if(k <= numOnes){
            ans= k;
        }
        
        return ans;
    }
};