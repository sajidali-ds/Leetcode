class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxlen=0;
        int maxfreq=0;
        int i=0;
        int j=0;
        int hash[26]={0};
        while(j<n){
            hash[s[j] - 'A']++;
            maxfreq=max(maxfreq,hash[s[j]-'A']);
            while((j-i+1)-maxfreq > k){
                hash[s[i]-'A']--;
                i++;
                maxfreq=0;
                for(int l=0;l<25;l++){
                    maxfreq=max(maxfreq,hash[l]);
                    
                }
            }
            
            maxlen=max(maxlen,j-i+1);
            j++;
            
        }
        return maxlen;
    }
};