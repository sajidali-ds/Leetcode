class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        for (int x : nums1) {
            if (x % 2 != mn % 2)
                return mn % 2 == 1;
        }

        return true;
    }
};