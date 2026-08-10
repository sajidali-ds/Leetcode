class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> maxh;
        for(int i=0;i<stones.size();i++){
            maxh.push(stones[i]);
        } 
            while(maxh.size() > 1){
                int first=maxh.top();
                maxh.pop();

                int second=maxh.top();
                maxh.pop();

                if(first != second){
                    maxh.push(first-second);
                }
            }
           

        if(maxh.empty()) {
            return 0;
        }

        return maxh.top();

    }
};