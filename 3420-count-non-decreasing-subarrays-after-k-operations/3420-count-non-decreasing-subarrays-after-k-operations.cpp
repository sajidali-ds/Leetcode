
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;

        int j = n - 1;

        deque<pair<int, int>> dq;

        for (int i = n - 1; i >= 0; i--) {

            int num = nums[i];
            int cnt = 1;

            // Merge smaller elements into current element
            while (!dq.empty() && dq.back().first < num) {

                int nextNum = dq.back().first;
                int nextCnt = dq.back().second;

                dq.pop_back();

                cnt += nextCnt;

                cost += 1LL * (num - nextNum) * nextCnt;
            }

            dq.push_back({num, cnt});

            // Reduce window if operations exceed k
            while (cost > k) {

                int rightmostNum = dq.front().first;
                int rightmostCnt = dq.front().second;

                dq.pop_front();

                cost -= rightmostNum - nums[j];
                j--;

                if (rightmostCnt > 1) {
                    dq.push_front({rightmostNum, rightmostCnt - 1});
                }
            }

            // Count valid subarrays
            ans += j - i + 1;
        }

        return ans;
    }
};
