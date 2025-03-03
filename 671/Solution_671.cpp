#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
`static_cast<long>` 是 C++ 中的一种类型转换操作，用于将一种数据类型显式转换为另一种数据类型。在这里，它的作用是将 `node->val`（通常是 `int` 类型）转换为 `long` 类型。

---

### 详细说明：
1. **为什么需要类型转换？**
   - 在代码中，`secondMin` 被定义为 `long` 类型（`long secondMin = LONG_MAX;`），而 `node->val` 是 `int` 类型。
   - 当我们需要将 `node->val` 与 `secondMin` 进行比较或赋值时，需要确保两者的类型一致，否则可能会导致数据溢出或精度丢失。
   - 使用 `static_cast<long>` 将 `node->val` 显式转换为 `long` 类型，可以避免这些问题。

2. **`static_cast` 的特点**：
   - `static_cast` 是 C++ 中最常用的类型转换操作符之一。
   - 它用于在编译时进行类型检查，确保转换是安全的。
   - 它只能用于具有一定关系的类型之间的转换（例如，数值类型之间的转换，或者基类和派生类之间的指针转换）。

3. **代码中的具体作用**：
   - 在 `secondMin = std::min(secondMin, static_cast<long>(node->val));` 这一行中：
     - `secondMin` 是 `long` 类型。
     - `node->val` 是 `int` 类型。
     - 使用 `static_cast<long>` 将 `node->val` 转换为 `long` 类型，以便与 `secondMin` 进行比较和赋值。

---

### 示例：
假设 `node->val` 的值为 `5`，`secondMin` 的值为 `LONG_MAX`（即 `9223372036854775807`）。

- 如果不进行类型转换：
  ```cpp
  secondMin = std::min(secondMin, node->val); // 这里会报错或产生警告
  ```
  编译器可能会提示类型不匹配，因为 `secondMin` 是 `long`，而 `node->val` 是 `int`。

- 使用 `static_cast<long>`：
  ```cpp
  secondMin = std::min(secondMin, static_cast<long>(node->val)); // 正确
  ```
  这里 `node->val` 被显式转换为 `long` 类型，可以与 `secondMin` 进行比较。

---

### 其他类型转换操作符：
C++ 中还有其他几种类型转换操作符，例如：
1. **`dynamic_cast`**：用于多态类型之间的转换（通常用于基类和派生类之间的指针或引用转换）。
2. **`const_cast`**：用于移除 `const` 或 `volatile` 属性。
3. **`reinterpret_cast`**：用于低级别的类型转换（例如将指针转换为整数）。

---

### 总结：
- `static_cast<long>` 是将 `int` 类型显式转换为 `long` 类型的安全方式。
- 在代码中，它的作用是确保 `node->val` 可以与 `secondMin`（`long` 类型）进行比较和赋值，避免类型不匹配的问题。

*/
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) return -1; // 如果树为空，返回 -1

        int minVal = root->val; // 根节点的值是最小值
        long secondMin = LONG_MAX; // 初始化第二小的值为最大值

        dfs(root, minVal, secondMin); // 调用 DFS 函数

        // 如果 secondMin 没有被更新，说明没有第二小的值
        return (secondMin != LONG_MAX) ? secondMin : -1;
    }

private:
    void dfs(TreeNode* node, int minVal, long& secondMin) {
        if (!node) return;

        // 如果当前节点的值大于 minVal，则更新第二小的值
        if (node->val > minVal) {
            secondMin = std::min(secondMin, static_cast<long>(node->val));
        }

        // 如果当前节点的值等于 minVal，则需要继续遍历其子树
        if (node->val == minVal) {
            dfs(node->left, minVal, secondMin);
            dfs(node->right, minVal, secondMin);
        }
    }
};
