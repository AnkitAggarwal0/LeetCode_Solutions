class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        std::vector<int> cum_sum(gain.size()); 
        std::partial_sum(gain.begin(), gain.end(), cum_sum.begin()); 
        cum_sum.insert(cum_sum.begin(), 0);
        return *std::max_element(cum_sum.begin(), cum_sum.end());
    }
};