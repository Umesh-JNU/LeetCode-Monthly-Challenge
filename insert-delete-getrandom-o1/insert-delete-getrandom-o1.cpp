class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> mpp;
    vector<int> v;
    RandomizedSet() {}
    
    bool insert(int val) {
        if(mpp.find(val) != mpp.end())
            return false;
        v.push_back(val);
        mpp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if(mpp.find(val) == mpp.end())
            return false;
        int idx = mpp[val];
        int last_val = v.back();
        v[idx] = last_val;
        v.pop_back();
        mpp[last_val] = idx;
        mpp.erase(val);   // important - this must be done at last because there might be the case that erasing val and idx will be same
        return true;
    }
    int getRandom() {
        int i = rand() % mpp.size();
        return v[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */