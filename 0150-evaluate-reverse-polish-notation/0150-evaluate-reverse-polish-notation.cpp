class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operation;

        for (std::string token : tokens){
            // if (token == "-" || token == "+" || token == "/" || token == "*")
            if(token.size() == 1 && !isdigit(token[0]))
            { 
                //operator
                int val = operation.top();
                operation.pop();
                int operand = operation.top();
                operation.pop();

                int op_res; 
                if(token == "-") op_res = operand - val; 
                else if (token == "+") op_res = operand + val; 
                else if (token == "*") op_res = operand * val; 
                else if (token == "/") op_res = operand / val; 
                
                operation.push(op_res);
                
            }
            else{
                operation.push(std::stoi(token));
            }
        }

        return operation.top();

    }
};