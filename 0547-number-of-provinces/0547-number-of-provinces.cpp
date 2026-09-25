class Solution {
public:

    void dfs(int city,vector<vector<int>>& isconnected ,vector<int>& visited){
        visited[city]=1;
        for(int i=0;i<isconnected.size();i++){
            if(isconnected[city][i]==1 &&visited[i]==0 ){
                dfs(i,isconnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> visited(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(i,isConnected,visited);
                provinces++;

                
            }
        }
        return provinces;
    }
};