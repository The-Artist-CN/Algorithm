#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int numJewelsInStones( string str , string target ){
    unordered_map<char,int> hashmap;
    for ( char c : str ){
        hashmap[c]++;
    }
    
    /*
    问题 1：变量 sum 未初始化
在函数 numJewelsInStones 中，变量 sum 没有初始化。这会导致未定义行为，因为在 C++ 中，局部变量如果未初始化，其值是随机的。
int sum;

修正：
将 sum 初始化为 0：


    */

/*
问题 2：unordered_map 的 contains 方法
unordered_map 的 contains 方法是 C++20 引入的。如果你使用的是 C++17 或更早的标准，unordered_map 不支持 contains 方法。

解决方案（适配 C++17 或更早版本）：
使用 find 方法代替 contains：
    for ( char c : target ){
        if ( hashmap.contains(c)){
            sum += hashmap[c];
        }
    }
*/
    int sum = 0;
    for ( char c : target ){
        if (hashmap.find(c) != hashmap.end()) {
            sum += hashmap[c];
        }
    }
    return sum;
}

int main() {
    string jewels = "aA";
    string stones = "aAAbbbb";
    cout << "宝石数量: " << numJewelsInStones(jewels, stones) << endl; // 输出 3

    jewels = "z";
    stones = "ZZ";
    cout << "宝石数量: " << numJewelsInStones(jewels, stones) << endl; // 输出 0

    return 0;
}
/*
在 C++ 中，unordered_map 是一种哈希表容器，用于存储键值对。hashmap.find(c) 的作用是查找键 c 是否存在于哈希表中，并返回一个迭代器。以下是为什么要写 hashmap.find(c) != hashmap.end() 的详细解释。

1. hashmap.find(c) 的作用
hashmap.find(c) 会返回一个迭代器：
如果键 c 存在于 unordered_map 中，返回指向该键的迭代器。
如果键 c 不存在，则返回 hashmap.end()，表示查找失败。
2. 为什么要用 != hashmap.end()
hashmap.end() 是一个特殊的迭代器，表示哈希表的末尾。它不指向任何有效的键值对，仅用于标记查找失败的情况。
当我们写 hashmap.find(c) != hashmap.end() 时，实际上是在检查键 c 是否存在于哈希表中：
如果 hashmap.find(c) != hashmap.end()，说明键 c 存在。
如果 hashmap.find(c) == hashmap.end()，说明键 c 不存在。
3. 为什么不能直接访问 hashmap[c]
在 C++ 中，直接访问 hashmap[c] 时，如果键 c 不存在，会自动插入一个默认值（通常是 0 或空值）。这可能导致意外行为
*/
