class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) return 0; 

        int i = 0; 
        int n = s.length();

        // Whitespace
        while (i<n && s[i] == ' '){
            i++;
        }

        if (i==n) return 0; 

        //Signedness
        int sign = 1; 
        if (s[i] == '-') {
            sign = -1; 
            i++;
        }
        else if (s[i] == '+'){
            i++;
        }
        //Conversion 
        long long result = 0; 
        while (i<n && isdigit(s[i])){
            int digit = s[i] - '0';
            result = result * 10 + digit; 

            if (sign * result < INT_MIN) return INT_MIN; 
            if (sign * result > INT_MAX) return INT_MAX;
            i++;
        }

        return static_cast<int>(result * sign);
    }
};