class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        vector<vector<char>> bucket(s.size() + 1);

        for (auto it : freq) {
            char ch = it.first;
            int count = it.second;
            bucket[count].push_back(ch);
        }

        string ans;

        for (int i = s.size(); i >= 1; i--) {
            for (char ch : bucket[i]) {
                ans.append(i, ch);   // append character 'i' times
            }
        }

        return ans;
    }
};