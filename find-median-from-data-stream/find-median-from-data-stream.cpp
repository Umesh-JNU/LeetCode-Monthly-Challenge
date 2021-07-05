class MedianFinder {
public:
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double>> minHeap;
    double median;
    int s, g;
    /** initialize your data structure here. */
    MedianFinder() { median = 0.0; s=0; g=0; }
    
    void addNum(int num) {
        s = minHeap.size();
        g = maxHeap.size();
        
        if(s==g){
            if(num > median){
                minHeap.push(num);
                median = minHeap.top();
            }
            else{
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        // right side has more elements
        else if(s > g){
            if(num > median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else{
                maxHeap.push(num);
            }
        }
        // left side has more elements
        else{
            if(num > median)
                minHeap.push(num);
            else{
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(s==g)
            return median;
        return (minHeap.top()+maxHeap.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */