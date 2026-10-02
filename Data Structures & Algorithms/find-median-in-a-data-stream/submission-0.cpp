class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        size++;
        if(size%2) {
           maxHeap.push(num);
        } else 
           minHeap.push(num);
        
        if(size>1) {
            int t = maxHeap.top(); 
            maxHeap.pop(); 
            int s = minHeap.top();
            minHeap.pop();
            if(t > s) {
                swap(t, s);
            }
            maxHeap.push(t);
            minHeap.push(s);
        }
    }
    
    double findMedian() {
        if(size%2) {
            return (double) maxHeap.top();
        } else return (maxHeap.top() + minHeap.top())/2.0;
    }
};
