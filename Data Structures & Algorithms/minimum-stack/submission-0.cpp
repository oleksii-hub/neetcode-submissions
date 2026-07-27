class MinStack {
    std::vector<int> vec;

public:
    MinStack() = default;
    
    void push(int val) {
        vec.push_back(val);
    }
    
    void pop() {
        vec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        int min = std::numeric_limits<int>::max();
        for (int num : vec)
        {
            min = std::min(min, num);
        }

        return min;
    }
};
