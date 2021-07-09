class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s;
        // next left smaller
        for (int i = 0; i < n; i++)
        {
            if (s.empty())
            {
                left[i] = 0;
                s.push(i);
            }
            else
            {
                while (!s.empty() && heights[s.top()] >= heights[i])
                    s.pop();
                left[i] = s.empty() ? 0 : s.top() + 1;
                s.push(i);
            }
        }

        // maximum bar inclusion in right
        while (!s.empty())
            s.pop();

        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                right[i] = n - 1;
                s.push(i);
            }
            else
            {
                while (!s.empty() && heights[s.top()] >= heights[i])
                    s.pop();
                right[i] = s.empty() ? n - 1 : s.top() - 1;
                s.push(i);
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (right[i] - left[i] + 1) * heights[i]);
        }
        return ans;
    }
};