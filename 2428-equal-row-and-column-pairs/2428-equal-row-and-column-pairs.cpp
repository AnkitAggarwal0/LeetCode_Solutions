class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int count = 0; 

        std::map<vector<int>, int> rowCounts; 
        for (int k = 0; k<n; k++){
            rowCounts[grid[k]]++;
        }

        for (int j = 0; j <n; j++){
            vector<int> col; 
            for (int i = 0; i<n; i++){
                col.push_back(grid[i][j]);
            }

            if (rowCounts.find(col) != rowCounts.end()){
                count += rowCounts[col]; 
            }
        }

        return count;
    }


};