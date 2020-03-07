#include <iostream>
#include <stack>

class MyQueue {
    std::stack<int> stack1, stack2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int num;

        for (int i = 0; i <= stack1.size(); ++i) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        num = stack2.top();
        stack2.pop();

        for (int i = 0; i <= stack2.size(); ++i) {
            stack1.push(stack2.top());
            stack2.pop();
        }

        return num;
    }

    /** Get the front element. */
    int peek() {
        int num;

        for (int i = 0; i <= stack1.size(); ++i) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        num = stack2.top();

        for (int i = 0; i <= stack2.size(); ++i) {
            stack1.push(stack2.top());
            stack2.pop();
        }

        return num;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty();
    }
};

int main() {
    int x = 1;

    MyQueue* ole = new MyQueue();
    ole->push(x);
    x = 2;
    ole->push(x);
    int yo = ole->peek();
    int yoyo = ole->pop();
    std::cout << yo << std::endl << yoyo << std::endl;
    bool heyhey = ole->empty();
    std::cout << (heyhey ? "TRUE" : "FALSE");
}
