class Solution {
public:
    bool isRotationPossible(vector<int>& blk, vector<int>& target) {
        int k = blk.size();
        vector<int> tmp = blk;
        sort(tmp.begin(), tmp.end());
        if (tmp != target) return false;
        int descents = 0;
        for (int i = 0; i < k; i++) {
            if (blk[i] > blk[(i + 1) % k]) descents++;
        }
        return descents <= 1;
    }


    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int result = 0;
        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;
            for (int start = 0; start < n; start += k) {
                vector<int> vec1(nums.begin() + start, nums.begin() + start + k);
                vector<int> vec2(sorted.begin() + start, sorted.begin() + start + k);

                if (!isRotationPossible(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }
            if (valid) result += k;
        }
        return result;
        
    }
};