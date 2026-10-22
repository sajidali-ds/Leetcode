class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int trap_height=0;
        int left_maxi=0;
        int right_maxi=0;
        vector<int> right(n,0);
        for (int i = n - 1; i >= 0; i--) {
            right_maxi = max(right_maxi, height[i]);
            right[i] = right_maxi;
        }

        for(int i=1;i<n-1;i++){
           left_maxi = max(left_maxi, height[i - 1]);
           trap_height += max(0, min(left_maxi, right[i + 1]) - height[i]);
        }
        return trap_height;
    }
};