class Solution {
public:
     multiset<long long> left, right;
    long long sumLeft = 0, sumRight = 0;

    void balance() {
        int required = (left.size() + right.size() + 1) / 2;

        while (left.size() > required) {
            auto it = prev(left.end());
            long long val = *it;

            left.erase(it);
            sumLeft -= val;

            right.insert(val);
            sumRight += val;
        }

        while (left.size() < required) {
            auto it = right.begin();
            long long val = *it;

            right.erase(it);
            sumRight -= val;

            left.insert(val);
            sumLeft += val;
        }
    }

    void insertNum(int val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumLeft += val;
        } else {
            right.insert(val);
            sumRight += val;
        }

        balance();
    }

    void eraseNum(int val) {
        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            sumLeft -= val;
        } else {
            it = right.find(val);
            right.erase(it);
            sumRight -= val;
        }

        balance();
    }
    long long getCost() {
    long long median = *left.rbegin();

    return median * left.size() - sumLeft
         + sumRight - median * right.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
       int n = nums.size();
        vector<long long> cost;
        for (int i = 0; i < n; i++) {

            insertNum(nums[i]);

            if (i >= x) {
                eraseNum(nums[i - x]);
            }

            if (i >= x - 1) {
                cost.push_back(getCost());
            }
        }
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {

            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {

                // Skip current element
                curr[i] = curr[i - 1];

                // Select window of size x
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};