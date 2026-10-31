class Solution {
public:
    int n;
    int canMakeBouqey(vector<int>& bloomDay, int mid, int k){
        int bouqeycount=0;
        int consecutive_flower=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i] <=  mid){
                consecutive_flower++;
            }
            else{
                consecutive_flower=0;
            }
            if(consecutive_flower == k ){
                bouqeycount++;
                consecutive_flower=0;
            }
        }
        return bouqeycount;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        n=bloomDay.size();
      
        int min_day=-1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){
            int mid=low +(high - low)/2;
            if(canMakeBouqey(bloomDay,mid,k) >= m){
                min_day=mid;
                high=mid-1;
            }
            else{
                low = mid +1;
            }
        }
        return min_day;
    }
};