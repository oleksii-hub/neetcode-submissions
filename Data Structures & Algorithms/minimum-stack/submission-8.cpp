class MinStack {
    std::int64_t min;
    std::vector<std::int64_t> st;

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

        std::int64_t back = st.back();
        st.pop_back();
        if (back < 0)
            min = min - back;

    }
    
    int top() {
        std::int64_t top = st.back();
        return top > 0 ? (top + min) : static_cast<int>(min);
    }
    
    int getMin() {
        return static_cast<int>(min);
    }
};
