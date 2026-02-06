class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size(); 
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq_left, pq_right; 

        int i = 0; 
        int j = n-1; 
        long long cost = 0; 

        while (k--){
            
            //Fill Queues 
            while(pq_left.size()<candidates && i<=j){
                pq_left.push(costs[i++]);            
            }
            while(pq_right.size()<candidates && i<=j){
                pq_right.push(costs[j--]);            
            }

            int val1 = pq_left.size() > 0 ? pq_left.top() : INT_MAX;
            int val2 = pq_right.size() > 0 ? pq_right.top() : INT_MAX;

            if (val1 <= val2){
                cost += val1;
                pq_left.pop();
            }
            else{
                cost+= val2;
                pq_right.pop();
            }
        }

        return cost;
    }
};