class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> altitudes(n+1,0);
        
        for(int i=1;i<=n;i++){
            altitudes[i]=altitudes[i-1]+gain[i-1];
        }
        return *max_element(altitudes.begin(),altitudes.end());
    }
};