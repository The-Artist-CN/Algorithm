#include <string>
#include <algorithm> // 用于 max 函数
#include <iostream>
using namespace std;

int findLUSlength(string a, string b) {
    // 如果两个字符串相等，则不存在特殊序列
    if (a == b) {
        return -1;
    }
    // 否则，返回较长字符串的长度
    return max(a.length(), b.length());
}

int main() {
    cout << findLUSlength("aba", "cdc") << endl; // 输出: 3
    cout << findLUSlength("aaa", "bbb") << endl; // 输出: 3
    cout << findLUSlength("aaa", "aaa") << endl; // 输出: -1
    return 0;
}
