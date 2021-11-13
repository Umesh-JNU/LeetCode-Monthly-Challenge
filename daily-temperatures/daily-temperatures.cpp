class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        int n = temp.size();
        stack<pair<int, int>> stk;
        stk.push(make_pair(n-1, temp[n-1]));
        temp[n-1] = 0;
        for (int i = n - 1; i >= 0; i--){
            while (!stk.empty() && temp[i] >= stk.top().second)
                stk.pop();

            pair<int, int> cur = make_pair(i, temp[i]);
            if(stk.empty())
                temp[i] = 0;
            else
                temp[i] = stk.top().first - i;

            stk.push(cur);
        }
        return temp;
    }
};