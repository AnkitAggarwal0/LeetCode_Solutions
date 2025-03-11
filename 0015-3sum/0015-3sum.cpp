class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        set<vector<int>> s; 
        vector<vector<int>> triplets; 

        for (int i = 0; i < nums.size(); i++){
            int left = i+1;
            int right = nums.size() - 1;
            while (left < right){
                int total = nums[left] + nums[right] + nums[i];
                if(total == 0){
                    s.insert({nums[i], nums[left], nums[right]});
                    left++; right--;
                }
                else if (total < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        for (auto trip:s)
            triplets.push_back(trip);
        return triplets;
    }
};