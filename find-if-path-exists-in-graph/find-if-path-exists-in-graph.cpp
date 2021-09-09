class Solution {
public:
    bool DFS(vector<vector<int>> &graph, vector<int> &visited, int current, int end)
    {
        if (current == end)
            return true;
        // if (visited[current])
        //     return false;

        visited[current] = 1;
        for (int i = 0; i < graph[current].size(); i++)
        {
            if (!visited[graph[current][i]] && DFS(graph, visited, graph[current][i], end))
                return true;
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>> &edges, int start, int end)
    {
        vector<vector<int>> graph(n);

        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited(n, 0);
        return DFS(graph, visited, start, end);
    }
};