class MedianFinder {
    priority_queue<int, vector<int>, less<int>> MaxHeapForSmallerSide;
    priority_queue<int, vector<int>, greater<int>> MinHeapForLargerSide;

   public:
    MedianFinder() {}

    void addNum(int num) {
        MaxHeapForSmallerSide.push(num);
        if (!MinHeapForLargerSide.empty() and MinHeapForLargerSide.top() < MaxHeapForSmallerSide.top()) {
            MinHeapForLargerSide.push(MaxHeapForSmallerSide.top());
            MaxHeapForSmallerSide.pop();
        }

        if (MaxHeapForSmallerSide.size() > MinHeapForLargerSide.size() + 1) {
            MinHeapForLargerSide.push(MaxHeapForSmallerSide.top());
            MaxHeapForSmallerSide.pop();
        }
        if (MinHeapForLargerSide.size() > MaxHeapForSmallerSide.size() + 1) {
            MaxHeapForSmallerSide.push(MinHeapForLargerSide.top());
            MinHeapForLargerSide.pop();
        }
    }

    double findMedian() {
        if (MaxHeapForSmallerSide.size() == MinHeapForLargerSide.size()) {
            return ((MaxHeapForSmallerSide.top() + MinHeapForLargerSide.top()) / 2.0);
        }
        else if(MaxHeapForSmallerSide.size() > MinHeapForLargerSide.size()){
            return MaxHeapForSmallerSide.top();
        }
        else{
            return MinHeapForLargerSide.top();
        }
    }
};
