class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentStr = "";
        int k = 0;

        for (char c : s){
            if (isdigit(c)){
                k = k * 10 + (c - '0');
            }
            else if (c == '['){
                countStack.push(k);
                stringStack.push(currentStr);
                currentStr = ""; 
                k = 0;
            }
            else if (c == ']'){
                string lastStr = stringStack.top(); 
                stringStack.pop(); 
                int repeats = countStack.top(); 
                countStack.pop(); 

                string temp = ""; 
                for (int i = 0; i < repeats; i++) temp += currentStr;

                currentStr = lastStr + temp;

            }
            else { //Normal Character
                currentStr += c;
            }
        }
        return currentStr;
    }
};