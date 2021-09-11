class Solution {
public:
    int calPoints(vector<string> &ops)
    {
        stack<int> record;
        for (int i = 0; i < ops.size(); i++){
            if(ops[i]=="C"){
                record.pop();
            }else{
                if(ops[i] == "D"){
                    ops[i] = to_string(stoi(ops[record.top()]) * 2);
                }else if(ops[i]=="+"){
                    int a = record.top();
                    record.pop();
                    int b = record.top();
                    record.push(a);
                    ops[i] = to_string(stoi(ops[a]) + stoi(ops[b]));
                }
                record.push(i);
            }
        }

        int ans = 0;
        while (!record.empty())
        {
            ans += stoi(ops[record.top()]);
            record.pop();
        }
        return ans;
    }
};