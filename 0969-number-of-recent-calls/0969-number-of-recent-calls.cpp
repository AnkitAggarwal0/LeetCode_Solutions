class RecentCounter {
public:
    std::queue<int> calls; 
    int counter = 0;
    RecentCounter() {     
    }
    
    int ping(int t) {
        calls.push(t);
        counter++;
        while (calls.front() < t-3000){
            calls.pop();
            counter--;
        }
        return counter;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */