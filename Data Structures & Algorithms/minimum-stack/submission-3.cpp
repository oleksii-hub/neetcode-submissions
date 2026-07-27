class MinStack {
    std::vector<int> vec;
    std::vector<int> mins;
public:
    MinStack()
    {
    }
    
    void push(int val) {
        int topVal = mins.empty() ? std::numeric_limits<int>::max() : mins.back();
        vec.push_back(val);
        mins.push_back(std::min(val, topVal));
    }
    
    void pop() {
        vec.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return mins.back();
    }
};
