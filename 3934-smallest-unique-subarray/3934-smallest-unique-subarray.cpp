class Solution {
public:
    using ll = long long;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll BASE = 100002;

    bool check(int len, vector<int>& nums) {
        int n = nums.size();

        ll power1 = 1, power2 = 1;
        for (int i = 1; i < len; i++) {
            power1 = (power1 * BASE) % MOD1;
            power2 = (power2 * BASE) % MOD2;
        }

        ll nextPower1 = (power1 * BASE) % MOD1;
        ll nextPower2 = (power2 * BASE) % MOD2;

        ll h1 = 0, h2 = 0;

        for (int i = 0; i < len; i++) {
            h1 = (h1 * BASE + nums[i]) % MOD1;
            h2 = (h2 * BASE + nums[i]) % MOD2;
        }

        map<pair<ll, ll>, int> freq;

        freq[{h1, h2}]++;
        for (int i = len; i < n; i++) {

            ll old = nums[i - len];
            ll curr = nums[i];

            h1 = (h1 * BASE - old * nextPower1 % MOD1 + curr + MOD1) % MOD1;

            h2 = (h2 * BASE - old * nextPower2 % MOD2 + curr + MOD2) % MOD2;

            freq[{h1, h2}]++;
        }
        for (auto& p : freq) {
            if (p.second == 1) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {

        int low = 1;
        int high = nums.size();

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, nums)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
