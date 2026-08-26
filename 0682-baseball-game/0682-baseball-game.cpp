class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
    
        int count1=0;
     
        int count3=0;
        
        for(int i=0;i<operations.size();i++){
            if(operations[i] != "+" && operations[i] != "D" && operations[i] != "C"){
                int x = stoi(operations[i]);
                st.push(x);
            }
            
            if(operations[i]=="+"){
                
                int first = st.top();
                st.pop();

                int second = st.top();

                st.push(first);
                st.push(first + second);
            } 
                
            if(operations[i]=="D"){
                count1=2 * st.top();
                st.push(count1);
            }
            if(operations[i]=="C"){
                st.pop();
            }
        }
        while(!st.empty()){
            count3 +=st.top();
            st.pop();
        }
        return count3;
        
    }
};