class FreqStack {
    unordered_map<int,int> valCnt;
    unordered_map<int,vector<int>> countToVal;
    int maxCount;
public:
    FreqStack() {
        this->maxCount = 0;
    }
    
    void push(int val) {
        valCnt[val]++; 
        if(valCnt[val] > this->maxCount) {
            this->maxCount = valCnt[val];
        }
        this->countToVal[valCnt[val]].push_back(val);
    }
    
    int pop() {
        int ele = countToVal[maxCount][countToVal[maxCount].size() - 1];
        valCnt[ele]--;
        countToVal[this->maxCount].pop_back();
        if(countToVal[this->maxCount].empty()) 
            this->maxCount--;
        return ele;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */