class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101);
        for (int x:nums) count[x]++;

        int running_sum = 0; 
        for (int i=0; i<101; i++){
            int temp = count[i];
            count[i] = running_sum; 
            running_sum += temp;
        }

        vector<int> result; 
        for (int j=0; j<nums.size(); j++){
            result.push_back(count[nums[j]]);
        }
        return result;
    }
};