class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> result;
        for (int i = 0; i < nums.size(); i++){
            int index = abs(nums[i]) - 1; 
            nums[index] = abs(nums[index]) * -1;
        }

        for (int j = 0; j < nums.size(); j++){
            if (nums[j] > 0) result.push_back(j+1);
        }

        return result;
    }

};