class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min=0;
        int row=grid.size();
        int col=grid[0].size();
        //   {r,c}{t}
        queue<pair<pair <int,int> ,int>> q;
        int vis[row][col];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }     
            }
        }
        int tm=0;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+delrow[i];
                int ncol=c+delcol[i];
                if(nrow >=0 && nrow < row && ncol >=0 && ncol < col && vis[nrow][ncol]!=2 &&
                 grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j]!=2 && grid[i][j]==1)
                   return -1;
            }
        }
        return tm;

    }
};