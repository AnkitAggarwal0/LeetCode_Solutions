class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int OneCount = 0; 
        int bestCount = 0;
        for (int i = 0; i < nums.size(); i++){
            if ( nums[i] == 1) {
                OneCount++; 
                if (OneCount >  bestCount) bestCount = OneCount;
                }
            else {
                OneCount = 0;
            }
        }
        return bestCount;
    }
};