class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int ele = 0;
        for(int i = 0; i < arr1.size(); i++) {
        int idx = lower_bound(arr2.begin(),arr2.end(),arr1[i] - d) - arr2.begin();

            if(idx == arr2.size() || arr2[idx] > arr1[i] + d) {
                ele++;
            }
        }

        return ele;
    }
};