class Solution {
public:
    int maxIndex(vector<int>& row) {
        int idx = 0;
        for (int i = 1; i < row.size(); i++) {
            if (row[i] > row[idx])
                idx = i;
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0, high = m - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            int col = maxIndex(mat[mid]);

            if (mat[mid][col] > mat[mid + 1][col])
                high = mid;
            else
                low = mid + 1;
        }

        return {low, maxIndex(mat[low])};
    }
};