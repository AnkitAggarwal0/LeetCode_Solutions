class Solution {
public:
    bool judgeCircle(string moves) {
        int x_pos = 0; int y_pos = 0; 

        for (auto move : moves){
            if (move == 'U') x_pos++; 
            else if (move == 'D') x_pos--;
            else if (move == 'L') y_pos--;
            else if (move == 'R') y_pos++;
        }

        return (x_pos == 0 && y_pos == 0);
    }
};