#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> queue1; // 主队列
    queue<int> queue2; // 辅助队列

public:
    MyStack() {}

    // 将元素压入栈顶
    void push(int x) {
        // 将新元素压入 queue2
        queue2.push(x);
        // 将 queue1 中的所有元素转移到 queue2
        while (!queue1.empty()) {
            queue2.push(queue1.front());
            queue1.pop();
        }
        // 交换 queue1 和 queue2
        swap(queue1, queue2);
    }

    // 移除并返回栈顶元素
    int pop() {
        int topElement = queue1.front();
        queue1.pop();
        return topElement;
    }

    // 返回栈顶元素
    int top() {
        return queue1.front();
    }

    // 判断栈是否为空
    bool empty() {
        return queue1.empty();
    }
};

// 测试代码
int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    printf("Top element: %d\n", stack.top());  // 输出 3
    printf("Popped element: %d\n", stack.pop());  // 输出 3
    printf("Is stack empty? %s\n", stack.empty() ? "true" : "false");  // 输出 false
    return 0;
}
