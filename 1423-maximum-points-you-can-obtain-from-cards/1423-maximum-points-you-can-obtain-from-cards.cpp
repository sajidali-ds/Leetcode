class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int leftsum=0;
        int maxsum=0;
        for(int i=0;i<k;i++){
            leftsum +=cardPoints[i];
            
        }
        maxsum=leftsum;
        int rindex=n-1;
        int rightsum=0;
        for(int i=k-1;i>=0;i--){
            leftsum -= cardPoints[i];
            rightsum+=cardPoints[rindex];
            rindex=rindex-1;
            maxsum = max(maxsum,leftsum + rightsum);
        }
        return maxsum;
    }
};