class Solution {
public:
    bool isPossible(vector<int>& target) {
        std::priority_queue<int> pq(target.begin(), target.end()); 
        long long total_sum = std::accumulate(target.begin(), target.end(), 0LL);

        while(pq.top()>1){
            int high = pq.top(); 
            pq.pop(); 
            long long rest_sum = total_sum - high;
            if (rest_sum == 0) return false;
            if (rest_sum == 1) return true;

            if (high % rest_sum == 0 || high < rest_sum) return false;
            int prev_val = high % rest_sum; 

            total_sum = total_sum - high + prev_val; 
            pq.push(prev_val);
        }

        return true;
    }
};