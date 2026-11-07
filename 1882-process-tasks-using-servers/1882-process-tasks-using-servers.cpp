class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> freeServers;

        priority_queue<tuple<long long,int,int>,
        vector<tuple<long long,int,int>>,
        greater<tuple<long long,int,int>>> busyServers;

        int n = servers.size();

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for(int i = 0; i < tasks.size(); i++) {

            time = max(time, (long long)i);

            while(!busyServers.empty() &&
                  get<0>(busyServers.top()) <= time) {

                auto [freeTime, weight, index] = busyServers.top();
                busyServers.pop();

                freeServers.push({weight, index});
            }

            if(freeServers.empty()) {

                time = get<0>(busyServers.top());

                while(!busyServers.empty() &&
                      get<0>(busyServers.top()) <= time) {

                    auto [freeTime, weight, index] = busyServers.top();
                    busyServers.pop();

                    freeServers.push({weight, index});
                }
            }
            auto server = freeServers.top();
            freeServers.pop();

            int weight = server.first;
            int index = server.second;

            ans.push_back(index);
            busyServers.push({
                time + tasks[i], weight, index
            });
        }

        return ans;
    }
};