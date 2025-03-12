from collections import deque

class MyStack:
    def __init__(self):
        self.queue1 = deque()  # 主队列
        self.queue2 = deque()  # 辅助队列

    def push(self, x: int) -> None:
        # 将新元素压入 queue2
        self.queue2.append(x)
        # 将 queue1 的所有元素依次转移到 queue2
        while self.queue1:
            self.queue2.append(self.queue1.popleft())
        # 交换 queue1 和 queue2 的角色
        self.queue1, self.queue2 = self.queue2, self.queue1

    def pop(self) -> int:
        # 移除并返回 queue1 的队首元素（即栈顶元素）
        return self.queue1.popleft()

    def top(self) -> int:
        # 返回 queue1 的队首元素（即栈顶元素）
        return self.queue1[0]

    def empty(self) -> bool:
        # 如果 queue1 为空，则栈为空
        return not self.queue1

# 测试代码
if __name__ == "__main__":
    stack = MyStack()
    stack.push(1)
    stack.push(2)
    print(stack.top())    # 输出 2
    print(stack.pop())    # 输出 2
    print(stack.empty())  # 输出 False
