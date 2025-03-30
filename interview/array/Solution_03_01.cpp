//三合一。描述如何只用一个数组来实现三个栈。 
//
// 你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。
//stackNum表示栈下标，value表示压入的值。 
//
// 构造函数会传入一个stackSize参数，代表每个栈的大小。 
//
// 示例 1： 
//
// 
// 输入：
//["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
//[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
// 输出：
//[null, null, null, 1, -1, -1, true]
//说明：当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。
// 
//
// 示例 2： 
//
// 
// 输入：
//["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
//[[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
// 输出：
//[null, null, null, null, 2, 1, -1, -1]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= stackNum <= 2 
// 
//
// Related Topics 栈 设计 数组 👍 79 👎 0
#include <iostream>
#include <vector>
using namespace std;

class TripleInOne {
private:
    vector<int> stack; // 存储所有栈的元素
    vector<int> sizes; // 记录每个栈的当前大小
    int stackSize; // 每个栈的最大大小
    const int numStacks = 3; // 栈的数量

public:
    // 构造函数，初始化栈大小
    TripleInOne(int stackSize):stackSize(stackSize) {
        stack.resize(stackSize * numStacks); // 初始化数组大小
        sizes.resize(numStacks, 0); // 初始化每个栈的大小为0
    }

    // 压入值
    void push(int stackNum, int value) {
        if (sizes[stackNum] < stackSize) {
            stack[stackNum * stackSize + sizes[stackNum]] = value; // 将值压入对应栈
            sizes[stackNum]++;
        }
    }

    // 弹出值
    int pop(int stackNum) {
        if (sizes[stackNum] == 0) {
            return -1; // 栈为空
        }
        int index = stackNum * stackSize + sizes[stackNum] - 1; // 获取栈顶索引
        int value = stack[index]; // 获取栈顶值
        sizes[stackNum]--; // 更新栈大小
        return value; // 返回栈顶值
    }

    // 查看栈顶值
    int peek(int stackNum) {
        if (sizes[stackNum] == 0) {
            return -1; // 栈为空
        }
        return stack[stackNum * stackSize + sizes[stackNum] - 1]; // 返回栈顶值
    }

    // 判断栈是否为空
    bool isEmpty(int stackNum) {
        return sizes[stackNum] == 0; // 判断栈大小是否为0
    }
};

int main() {
    // 示例 1
    TripleInOne* obj1 = new TripleInOne(1); // 每个栈的大小为1
    obj1->push(0, 1);
    obj1->push(0, 2); // 不会压入，因为栈已满
    cout << obj1->pop(0) << endl; // 输出 1
    cout << obj1->pop(0) << endl; // 输出 -1 (栈为空)
    cout << obj1->isEmpty(0) << endl; // 输出 true (栈为空)
    delete obj1; // 释放内存

    // 示例 2
    TripleInOne* obj2 = new TripleInOne(2); // 每个栈的大小为2
    obj2->push(0, 1);
    obj2->push(0, 2);
    obj2->push(0, 3); // 不会压入，因为栈已满
    cout << obj2->pop(0) << endl; // 输出 2
    cout << obj2->pop(0) << endl; // 输出 1
    cout << obj2->pop(0) << endl; // 输出 -1 (栈为空)
    cout << obj2->peek(0) << endl; // 输出 -1 (栈为空)
    cout << obj2->isEmpty(0) << endl; // 输出 true (栈为空)
    delete obj2; // 释放内存

    return 0;
}

