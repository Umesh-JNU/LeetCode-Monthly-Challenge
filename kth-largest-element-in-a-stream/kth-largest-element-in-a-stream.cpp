class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto x: nums){
            if(minHeap.size() < k)
                minHeap.push(x);
            else{
                if(x > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(x);
                }
            }
        }
    }
    
    int add(int val) {
        // cout << minHeap.size() << endl; 
        // cout << val << " " << (minHeap.size()<K ? 'a' : minHeap.top()) << endl;
        if(minHeap.size() < K){
            minHeap.push(val);
        }
        else if(val > minHeap.top()){
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
private:
    int K;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */