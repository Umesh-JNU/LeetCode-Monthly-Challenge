class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int n = gas.size();
    /* Brute force - considering each index as potential starting point */
    /*
    for (int i = 0; i < gas.size(); i++){
        int j = i, g = 0;
        while(1){
            g += (gas[j] - cost[j]);
            if(g < 0)
                break;
            j++;
            if(j == i)
                return i;
            if(j >= n)
                j = 0;
        }
    }
    return -1;
    */

    /* Optimized way - linear time */
    int total = 0, cur = 0, idx = 0;
    for (int i = 0; i < n; i++){
        total += gas[i] - cost[i];
        cur += gas[i] - cost[i];
        if(cur < 0){
            cur = 0;
            idx = i + 1;
        }
    }
    return total < 0 ? -1 : idx;
}
};