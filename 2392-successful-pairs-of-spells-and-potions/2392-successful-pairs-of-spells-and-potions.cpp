class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.size() > 0 ? potions.begin() : potions.end(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs(n);

        for (int i = 0; i < n; i++) {
            int left = 0;
            int right = m - 1;
            int first_valid_idx = m; // Default to m (meaning 0 pairs found)

            while (left <= right) {
                int mid = left + (right - left) / 2;
                // Cast to long long to prevent overflow
                if ((long long)potions[mid] * spells[i] >= success) {
                    first_valid_idx = mid;
                    right = mid - 1; // Look for an even smaller valid potion
                } else {
                    left = mid + 1;
                }
            }
            pairs[i] = m - first_valid_idx;
        }
        return pairs;
    }
};