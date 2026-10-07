class Solution {
public:
   int m,n;
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int idx){
        if(idx==word.size())
           return true;
        if( i < 0 || j < 0 || i >=m || j >=n || board[i][j] != word[idx])
           return false;
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, word, i+1, j, idx+1) ||
                     dfs(board, word, i-1, j, idx+1) ||
                     dfs(board, word, i, j+1, idx+1) ||
                     dfs(board, word, i, j-1, idx+1);
        board[i][j]=temp;
        return found;
   }

    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
         n=board[0].size();
        int freq[128] = {0};
        int need[128] = {0};

        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                freq[board[i][j]]++;

        
        for (int k = 0; k < word.size(); k++)
            need[word[k]]++;

        
        for (int c = 0; c < 128; c++)
            if (need[c] > freq[c])
                return false;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
};