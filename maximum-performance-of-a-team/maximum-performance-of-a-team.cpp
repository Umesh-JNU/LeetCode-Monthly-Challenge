class Solution {
public:
    #define ll long long
    #define MOD 1000000007
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<ll, ll>> engineer;
        for (int i = 0; i < n; i++){
            engineer.push_back(make_pair(efficiency[i], speed[i]));
        }
        sort(engineer.rbegin(), engineer.rend());

        ll ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++){
            pq.push(engineer[i].second);

            sum += engineer[i].second;

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, sum * engineer[i].first);
        }

        return ans%MOD;
    }
};