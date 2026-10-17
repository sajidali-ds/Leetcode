class Solution {
public:
    int digitSum(int n) {
        int s = 0;
        while (n) {
            s += n % 10;
            n /= 10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
         int n = nums.size();

        
        vector<array<int, 3>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {digitSum(nums[i]), nums[i], i};
        }

        sort(arr.begin(), arr.end());

        
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arr[i][2] == i) continue;

            int cycleLen = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j][2];
                cycleLen++;
            }
            swaps += cycleLen - 1;
        }

        return swaps;
    }
};