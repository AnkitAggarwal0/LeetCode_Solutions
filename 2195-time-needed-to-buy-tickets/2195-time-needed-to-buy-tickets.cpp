class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        std::queue<pair<int,int>> people; 
        for (int i = 0; i < tickets.size(); i++) people.push({tickets[i],i});

        int time = 0; 

        while (!people.empty()){
            std::pair<int, int> current = people.front();
            people.pop();

            time++;
            current.first--; 

            if (current.second == k && current.first == 0) return time; 
            
            if (current.first > 0) people.push(current);
        }
        return time;
    }
};