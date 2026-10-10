class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
       long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<int> diffs(n);
        long long total = 0;

        int mx = 0;
        for (int i = 0; i < n; i++) {
            diffs[i] = abs(nums1[i] - nums2[i]);
            total += diffs[i];
            mx = max(mx, diffs[i]);
        }
        if (total <= k) return 0;

        vector<long long> cnt(mx + 2, 0);
        for (int d : diffs) cnt[d]++;

        for (int v = mx; v > 0; v--) {
            if (cnt[v] == 0) continue;
            if (k >= cnt[v]) {
                k -= cnt[v];
                cnt[v - 1] += cnt[v];
                cnt[v] = 0;
            } else {
                cnt[v] -= k;
                cnt[v - 1] += k;
                k = 0;
                break;
            }
        }

        long long ans = 0;
        for (int v = 0; v <= mx; v++) {
            ans += cnt[v] * (long long)v * v;
        }
        return ans;
    }


};