class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftsum=0;
        int sum=0;
        int rightsum=0;
        for(int i=0;i<k;i++){
            leftsum += cardPoints[i];

        }
        sum = leftsum;
        int index= n-1;
        for(int i=k-1 ;i >=0 ;i--){
            leftsum -= cardPoints[i];
            rightsum += cardPoints[index];
            index--;
            sum=max(sum,leftsum+rightsum);
        }
        return sum;
    }
};