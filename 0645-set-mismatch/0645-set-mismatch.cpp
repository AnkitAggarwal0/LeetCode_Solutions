class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    vector<int> result(2); 

    long long n = nums.size(); 
    long long idealSum = n * (n+1) / 2; 
    long long sum = std::accumulate(nums.begin(), nums.end(), 0); 

    long long eq1 = sum - idealSum;

    long long idealSquaresSum = idealSum * (2*n+1) / 3; 
    long long sum_sq = std::accumulate(nums.begin(), nums.end(), 0LL, [](long long  total, int n) {
        return total + (static_cast<long long>(n) * n);
    });

    long long eq2 = sum_sq - idealSquaresSum;
    long long eq3 = eq2/eq1; 

    result[0] = (int)(eq1 + eq3)/2;
    result[1] = (int)result[0] - eq1; 

    return result;
    }
};
