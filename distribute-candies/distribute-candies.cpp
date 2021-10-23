class Solution {
public:
   int distributeCandies(vector<int> &candyType)
{
    set<int> hash_map;
    int n = candyType.size();
    for (int i = 0; i < n; i++){
        if(hash_map.count(candyType[i]) == 0)
            hash_map.insert(candyType[i]);
        if(hash_map.size() == n/2)
            break;
    }
    return hash_map.size();
}
};