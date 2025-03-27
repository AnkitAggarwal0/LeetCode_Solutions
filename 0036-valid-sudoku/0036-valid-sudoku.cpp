class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i = 0; i < 9; i++){
            vector<int> freq_rows(10,0);
            vector<int> freq_cols(10,0);
            for (int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    if(freq_rows[num]++) return false;
                }
                if(board[j][i] != '.'){
                    int num = board[j][i] - '0';
                    if(freq_cols[num]++) return false;
                }
            }

            vector<int> freq_boxes(10,0); 
            if(i % 3 == 0){
                for(int jdx = 0; jdx < 9; jdx++){
                    for(int kdx = i; kdx < i+3; kdx++){
                        if(board[kdx][jdx] != '.'){
                            int num = board[kdx][jdx] - '0'; 
                            freq_boxes[num]++; 
                        }
                    }
                    if(jdx%3==2){
                        for (int ugh=0; ugh < 10; ugh++){
                            if(freq_boxes[ugh]>1) return false;
                            else freq_boxes[ugh]=0;
                        }
                    }
                }
            }
        }
        return true; 
    }
};