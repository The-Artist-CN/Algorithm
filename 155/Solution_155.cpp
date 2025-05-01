class MinStack {
private:
    stack<int> normal_stack;
    stack<int> min_stack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        normal_stack.push(val);
        if (min_stack.empty()||min_stack.top() > val){
            min_stack.push(val);
        } else {
            min_stack.push(min_stack.top());
        }
    }
    
    void pop() {
        normal_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return normal_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
