class Solution {
public:

    vector<string> removeAnagrams(vector<string>& words) {
        
        int n=words.size();
        vector<string> ans;
        for(int i=0;i<n;i++){
            string temp=words[i];
            sort(temp.begin(),temp.end());
            if(i==0){
                ans.push_back(words[i]);
            }
            else{
                string prev=words[i-1];
                sort(prev.begin(),prev.end());
                if(temp != prev ){
                    ans.push_back(words[i]);
                }
            }
        }
        return ans;
    }
};