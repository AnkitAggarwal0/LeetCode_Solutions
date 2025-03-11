class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int marker = -101; 
        int count = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i ++){
            if (nums[i] != marker & marker < nums[i]) {
                nums[index++] = nums[i];
                marker = nums[i];
                count++;
            }

        }
        return count;
    }
};