class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi=0;
        int n=sentences.size();
        for(int i=0;i<n;i++){
            int count=1;
            for(char ch : sentences[i]) {
                if(ch == ' ') {
                    count++;
                }
            }
            maxi=max(maxi,count);

        }
        return maxi;
    }
};