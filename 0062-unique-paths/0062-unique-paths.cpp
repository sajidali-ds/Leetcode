class Solution {
public:
    int validpath(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i >=m || j >= n)
            return 0;
        
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];

        
        int down=validpath(i+1,j,m,n,dp);
        int right=validpath(i,j+1,m,n,dp);
        return dp[i][j]=down+right;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return validpath(0,0,m,n,dp);
    }
};