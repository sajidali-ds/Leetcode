
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n), newAdj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> newParent(n, -1);

        function<void(int)> dfs1 = [&](int u) {
            int c = s[u] - 'a';

            int old = last[c];

            if (old == -1) {
                newParent[u] = parent[u];
            } else {
                newParent[u] = old;
            }

            last[c] = u;

            for (int v : adj[u]) {
                dfs1(v);
            }

            last[c] = old;
        };

        dfs1(0);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        function<void(int)> dfs2 = [&](int u) {
            for (int v : newAdj[u]) {
                dfs2(v);
                ans[u] += ans[v];
            }
        };

        dfs2(0);

        return ans;
    }
};
