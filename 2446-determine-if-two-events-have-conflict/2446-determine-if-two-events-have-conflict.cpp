class Solution {
public:
    int convert(string s,int i){
        return(s[i]-'0')*10 + (s[i+1]-'0');
    }
  
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int h1=convert(event1[0],0);
        int h2=convert(event1[1],0);
        int m1=convert(event1[0],3);
        int m2=convert(event1[1],3);

        int h3=convert(event2[0],0);
        int h4=convert(event2[1],0);
        int m3=convert(event2[0],3);
        int m4=convert(event2[1],3);

        int t1=h1*60+m1;
        int t2=h2*60+m2;
        int t3=h3*60+m3;
        int t4=h4*60+m4;

        if((t1 <= t3 && t2 >= t3) || (t1 >=t3 && t4 >= t1)){
            return true;
        }
        return false;
        
        
    }
};