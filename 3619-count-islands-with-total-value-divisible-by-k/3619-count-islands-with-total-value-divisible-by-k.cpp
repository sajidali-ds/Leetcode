class Solution {
public:
    int row,col;
    vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
    long long dfs(int i,int j,vector<vector<int>>& grid){
        long long sum=grid[i][j];
        grid[i][j]=0;  
        for(vector <int>& dir:directions){
            int i_=i+dir[0];
            int j_=j+dir[1];
            if( i_ >=0 && i_ <row && j_ >=0 && j_ < col && grid[i_][j_] > 0 ){
                sum += dfs(i_,j_,grid);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        row=grid.size();
        col=grid[0].size();
        int count=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] > 0){
                    long long sum = dfs(i,j,grid);
                    if(sum % k ==0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};