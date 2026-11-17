class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;
                    for (int r = 0; r < d; r++) {
                        int l = i + r;
                        int right = i + len - d + r;

                        while (l < right) {
                            if (s[l] != s[right]) {
                                changes++;
                            }
                            l += d;
                            right -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }
        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int parts = 1; parts <= k; parts++) {
                for (int h = i - 2; h >= 0; h--) {
                    if (dp[h][parts - 1] == INF) continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        dp[h][parts - 1] + cost[h][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};