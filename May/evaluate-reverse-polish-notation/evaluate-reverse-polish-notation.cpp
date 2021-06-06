class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int a, b;
        for(int i=0; i<tokens.size(); i++){
            if (tokens[i] == "+"){
                a = stk.top(); stk.pop();
                stk.top() += a;
            }
            else if(tokens[i] == "-"){
                a = stk.top(); stk.pop();
                stk.top() -= a;
            }
            else if(tokens[i] == "*"){
                a = stk.top(); stk.pop();
                stk.top() *= a;
            }
            else if (tokens[i] == "/"){        
                a = stk.top(); stk.pop();
                stk.top() /= a;
            }
            else{
                stk.push(stoi(tokens[i]));
            }
        }

        int res = stk.top();
        stk.pop();
        return res;
    }
};