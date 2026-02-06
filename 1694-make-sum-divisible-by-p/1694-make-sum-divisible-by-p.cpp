class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (int n : nums) totalSum += n;
        
        int rem = totalSum % p;
        if (rem == 0) return 0; // Already divisible

        std::unordered_map<int, int> last_seen;
        last_seen[0] = -1; // Base case: prefix sum of 0 at index -1
        
        long long currentSum = 0;
        int minLen = nums.size();
        
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            int cur_rem = currentSum % p;
            
            // What remainder do we need to subtract to get 'rem'?
            int target_rem = (cur_rem - rem + p) % p;
            
            if (last_seen.count(target_rem)) {
                minLen = std::min(minLen, i - last_seen[target_rem]);
            }
            
            // Always update to the latest index to keep subarrays short
            last_seen[cur_rem] = i;
        }
        
        return (minLen >= nums.size()) ? -1 : minLen;
    }
};