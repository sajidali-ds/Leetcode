class Solution {
public:
    struct Compare {
        bool operator()(pair<int,string> a, pair<int,string> b) {
            if(a.first == b.first)
                return a.second < b.second;
            else
                return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for(string word : words) {
            mp[word]++;
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare> minh;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            minh.push({it->second, it->first});

            if(minh.size() > k) {
                minh.pop();
            }
        }
        vector<string> ans;
        while(minh.size() > 0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};