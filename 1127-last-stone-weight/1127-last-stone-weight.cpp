class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int> st(stones.begin(), stones.end()); 

        while (st.size()>1){
            int highest = st.top(); 
            st.pop(); 

            int second = st.top(); 
            st.pop(); 

            if (highest != second) st.push (highest - second); 
        }
        return st.empty() ? 0:st.top();
    }
};