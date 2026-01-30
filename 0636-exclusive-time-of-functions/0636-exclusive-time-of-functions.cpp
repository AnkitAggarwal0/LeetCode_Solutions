class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int fn_id, timestamp, prev_time=0;
        vector<int> times(n);
        std::stack<int> currentFn;
        

        for (std::string& log : logs){
            int pos1 = log.find(':');
            int pos2 = log.find_last_of(':');
            int fn_id = stoi(log.substr(0, pos1));
            string cmd = log.substr(pos1 + 1, pos2 - pos1 - 1);
            int timestamp = stoi(log.substr(pos2 + 1));

            if (cmd == "start"){
                if(!currentFn.empty()){
                    times[currentFn.top()]+= timestamp-prev_time;
                }
                currentFn.push(fn_id);
                prev_time = timestamp;
            }
            else{
                times[currentFn.top()]+= timestamp-prev_time+1;
                prev_time = timestamp+1;
                currentFn.pop();
            }
        }

        return times;
    }
};