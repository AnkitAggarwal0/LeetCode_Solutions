class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> triplets; 

        for (int i = 0; i < nums.size(); i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = nums.size() - 1;
            while (left < right){
                int total = nums[left] + nums[right] + nums[i];
                if(total == 0){
                    vector<int> trip = {nums[i], nums[left], nums[right]};
                    triplets.push_back(trip);
                    left++; right--;
                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
                else if (total < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }

        return triplets;
    }
};