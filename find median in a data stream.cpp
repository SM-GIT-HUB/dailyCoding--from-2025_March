class MedianFinder {
public:
    class obj {
    public:
        priority_queue<int> left;
        priority_queue<int, vector<int>, greater<int> > right;

        void balanceHeaps()
        {
            int subnum = left.size() - right.size();

            if (subnum == 2)
            {
                right.push(left.top());
                left.pop();
            }
            else if (subnum == -2)
            {
                left.push(right.top());
                right.pop();
            }
        }

        double getMedian()
        {
            int sizenum = left.size() - right.size();

            if (sizenum > 0) {
                return left.top();
            }
            else if (sizenum < 0) {
                return right.top();
            }
            else
                return (left.top() + right.top()) / double(2);
        }
    };

    obj* main = nullptr;

    MedianFinder() {
        main = new obj();
    }
    
    void addNum(int num) {
        if (main->left.empty() || num <= main->left.top()) {
            main->left.push(num);
        }
        else
            main->right.push(num);

        main->balanceHeaps();
    }
    
    double findMedian() {
        double ans = main->getMedian();
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
