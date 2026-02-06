class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double best_average = 0.0; 
        double current_average =  0.0; 

        //First Window 
        for (int i = 0; i < k; i++){
            current_average += nums[i];
        }
        best_average = current_average;
        for (int i = k; i < nums.size(); i++){
            current_average += (nums[i] - nums[i-k]);
            if (current_average > best_average) best_average = current_average;
        }

        return best_average/k;


    }
};