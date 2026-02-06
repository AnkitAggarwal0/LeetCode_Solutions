class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        if (nums.size() ==1) return 0;
        std::sort(nums.begin(), nums.end()); 

        int step_count = 0; 
        int total_count = 0;

        for (int i = 1; i<nums.size(); ++i){
            if (nums[i-1] < nums[i]) step_count++; 

            total_count += step_count;
        }

        return total_count;
        
    }
};