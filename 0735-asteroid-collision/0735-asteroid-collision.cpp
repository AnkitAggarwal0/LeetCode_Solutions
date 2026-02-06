class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> survivors; 

        for (int i = 0; i < asteroids.size(); i++){
            while (!survivors.empty() && survivors.back() > 0 && asteroids[i] < 0){
                int surv = abs(survivors.back()); 
                int ast = abs(asteroids[i]); 

                if (ast > surv) {
                    survivors.pop_back(); 
                    continue;
                }
                if (ast == surv){
                    survivors.pop_back();
                }

                goto destroyed;
                
            }
            survivors.push_back(asteroids[i]);

            destroyed:;
        }

        return survivors;
    }
};