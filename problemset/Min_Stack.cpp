class MinStack {
private:
    stack<int> value;
    stack<int> minv;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        value.push(x);
        if (minv.empty() || minv.top() > x) {
            minv.push(x);
        } else {
            minv.push(minv.top());
        }
    }

    void pop() {
        value.pop();
        minv.pop();
    }

    int top() {
        return value.top();
    }

    int getMin() {
        return minv.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
