class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> prevLess(n), nextLess(n);
        vector<int> prevGreater(n), nextGreater(n);

        stack<int> st;

        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                prevLess[i] = -1;
            } else {
                prevLess[i] = st.top();
            }

            st.push(i);
        }

         while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                nextLess[i] = n;
            } else {
                nextLess[i] = st.top();
            }

            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                prevGreater[i] = -1;
            } else {
                prevGreater[i] = st.top();
            }

            st.push(i);
        }
         while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                nextGreater[i] = n;
            } else {
                nextGreater[i] = st.top();
            }

            st.push(i);
        }
         long long minSum = 0;
        long long maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prevLess[i];
            long long right = nextLess[i] - i;

            minSum += 1LL * nums[i] * left * right;
        }

        for (int i = 0; i < n; i++) {
            long long left = i - prevGreater[i];
            long long right = nextGreater[i] - i;

            maxSum += 1LL * nums[i] * left * right;
        }

        return maxSum - minSum;

    }
};