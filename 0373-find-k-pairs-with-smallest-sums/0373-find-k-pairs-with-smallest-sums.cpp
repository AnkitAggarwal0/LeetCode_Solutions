class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        typedef pair<int, pair<int,int>> Element; 
        std::priority_queue<Element, vector<Element>, std::greater<Element>> pq; 

        for (int i = 0; i<nums1.size() && i<k; i++){
            pq.push({nums1[i]+nums2[0], {i, 0}});
        } 

        vector<vector<int>> result; 
        while(k-- > 0 && !pq.empty()){
            auto top = pq.top();
            int i = top.second.first;
            int j = top.second.second;
            result.push_back({nums1[i], nums2[j]});
            pq.pop();

            if (j+ 1 < nums2.size()){
                pq.push({nums1[i]+nums2[j+1], {i,j+1}});
            }
        }

        return result;
    }
};