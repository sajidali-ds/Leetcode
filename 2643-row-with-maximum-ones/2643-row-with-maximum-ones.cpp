class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        unordered_map<int,int> mp;
        int m=mat.size();
        int n=mat[0].size();

        int maxOne=0;
        int row=0;
        for(int i=0;i<m;i++){
            int count =0;
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1)
                    count++;
            }
            if(count > maxOne){
                maxOne=count;
                row=i;
            }
        }
        return {row,maxOne};
    }
};