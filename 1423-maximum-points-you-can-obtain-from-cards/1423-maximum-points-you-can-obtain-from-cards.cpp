class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftsum=0;
        int sum=0;
        int rightsum=0;
        for(int i=0;i<k;i++){
            leftsum =leftsum + cardPoints[i];

        }
        sum = leftsum;
        int index= n-1;
        for(int i=k-1 ;i >=0 ;i--){
            leftsum = leftsum - cardPoints[i];
            rightsum =rightsum + cardPoints[index];
            index--;
            sum=max(sum,leftsum+rightsum);
        }
        return sum;
    }
};