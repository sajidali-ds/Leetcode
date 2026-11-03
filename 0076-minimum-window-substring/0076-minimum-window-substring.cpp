class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        vector<int> freq(128, 0);

        for (char c : t) {
            freq[c]++;
        }
       
        int i=0;
        int j=0;
        int required = t.size();
        int min_size = INT_MAX;
        int start = 0;
        while (j < s.size()) {

            if (freq[s[j]] > 0) {
                required--;
            }

            freq[s[j]]--;

            while (required == 0) {

                if (j - i + 1 < min_size) {
                    min_size = j - i + 1;
                    start = i;
                }

                freq[s[i]]++;

                if (freq[s[i]] > 0) {
                    required++;
                }

                i++;
            }

            j++;
        }

        if (min_size == INT_MAX) return "";

        return s.substr(start, min_size);
        
        
    }
};