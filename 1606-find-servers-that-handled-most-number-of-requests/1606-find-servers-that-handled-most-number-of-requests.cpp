class Solution {
public:
    typedef pair<int,int> P; 
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available_servers;
        for(int i=0;i<k;i++){
            available_servers.insert(i);
        }
        priority_queue<P,vector <P>, greater<P>> busyservers;
        vector<int> countRequest(k,0);
        for(int i=0;i<arrival.size();i++){
            int time=arrival[i];
            while(!busyservers.empty() && busyservers.top().first <=time){
                int server=busyservers.top().second;
                busyservers.pop();
                available_servers.insert(server);
            }
            int target=i%k;
            auto it=available_servers.lower_bound(target);
            if(it==available_servers.end()){
                it=available_servers.begin();
            }
            if(available_servers.empty()){
                continue;
            }
            int targetservers = *it;
            available_servers.erase(it);
            busyservers.push({time+load[i],targetservers});
            countRequest[targetservers]++;
        }
        vector<int> result;
        int maxRequest= *max_element(countRequest.begin(),countRequest.end());
        for(int i=0;i<k;i++){
            if(countRequest[i]==maxRequest){
                result.push_back(i);
            }
        }
        return result;
    }
};