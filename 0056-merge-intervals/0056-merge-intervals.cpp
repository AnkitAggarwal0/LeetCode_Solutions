class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result; 
        if (intervals.empty()) return result; 

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            
            vector<int>& lastInterval = result.back();

           
            if (intervals[i][0] <= lastInterval[1]) {
               
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            } else {
                
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};