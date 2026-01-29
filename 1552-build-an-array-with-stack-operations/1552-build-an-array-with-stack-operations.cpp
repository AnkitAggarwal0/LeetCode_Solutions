class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int curr_stream_num = 1; 
        int target_idx = 0; 
        vector<string> result;
        while (target_idx < target.size() && curr_stream_num <= n){
            result.push_back("Push");
            if (curr_stream_num == target[target_idx]) target_idx++;
            else result.push_back("Pop");
            curr_stream_num++;
        }
        return result;
    }
};