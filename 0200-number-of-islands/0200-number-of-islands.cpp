class Solution {
public:

    void bfs(int i, int j, vector<vector<int>>& visited,
             vector<vector<char>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;

        q.push({i, j});
        visited[i][j] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = r + delRow[k];
                int nc = c + delCol[k];

                if(nr >= 0 && nr < row &&
                   nc >= 0 && nc < col &&
                   grid[nr][nc] == '1' &&
                   !visited[nr][nc]) {

                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));

        int island = 0;

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {

                if(!visited[i][j] && grid[i][j] == '1') {

                    island++;

                    bfs(i, j, visited, grid);
                }
            }
        }

        return island;
    }
};