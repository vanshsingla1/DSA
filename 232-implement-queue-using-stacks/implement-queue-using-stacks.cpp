class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {}

    void push(int x) {
        // insert x into input stack
        input.push(x);
    }

    int pop() {
        // check if output isn't empty then return output.top() otherwise
        // transfer whole input to output stack
        if (!output.empty()) {
            int val = output.top();
            output.pop();
            return val;
        }
        // output is empty now transfer input into output
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        // check if output isn't empty then return output.top() otherwise
        // transfer whole input to output stack
        if (!output.empty()) {
            return output.top();
        }
        // output is empty now transfer input into output
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }

    bool empty() {
        if (input.empty() && output.empty()) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */