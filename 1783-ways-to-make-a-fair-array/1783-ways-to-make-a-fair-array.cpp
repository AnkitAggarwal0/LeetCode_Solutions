class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int totalEven = 0, totalOdd = 0;
        int n = nums.size();

        // Step 1: Calculate total sums for even and odd indices
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) totalEven += nums[i];
            else totalOdd += nums[i];
        }

        int currentEven = 0, currentOdd = 0;
        int fairCount = 0;

        // Step 2: Iterate and "remove" each index mentally
        for (int i = 0; i < n; ++i) {
            // Calculate sums after removing nums[i]
            int evenSumAfterRemoval, oddSumAfterRemoval;

            if (i % 2 == 0) {
                // Remove an even index
                evenSumAfterRemoval = currentEven + (totalOdd - currentOdd);
                oddSumAfterRemoval = currentOdd + (totalEven - currentEven - nums[i]);
            } else {
                // Remove an odd index
                evenSumAfterRemoval = currentEven + (totalOdd - currentOdd - nums[i]);
                oddSumAfterRemoval = currentOdd + (totalEven - currentEven);
            }

            if (evenSumAfterRemoval == oddSumAfterRemoval) {
                fairCount++;
            }

            // Step 3: Update prefix sums for the next iteration
            if (i % 2 == 0) currentEven += nums[i];
            else currentOdd += nums[i];
        }

        return fairCount;
    }
};