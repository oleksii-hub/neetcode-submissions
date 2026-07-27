class MinStack {
    long min;
    std::vector<long> st;

public:
    MinStack() = default;
    
    void push(int val) {
        if (st.empty())
        {
            st.push_back(0);
            min = val;
        }
        else
        {
            st.push_back(val - min);
            if (val < min)
                min = val;
        }
    }
    
    void pop() {
        if (st.empty())
            return;

        long back = st.back();
        st.pop_back();
        if (back < 0)
            min = min - back;

    }
    
    int top() {
        long top = st.back();
        return top > 0 ? (top + min) : static_cast<int>(min);
    }
    
    int getMin() {
        return static_cast<int>(min);
    }
};
