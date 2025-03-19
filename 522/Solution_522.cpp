#include <vector>
#include <iostream>
#include <string>
#include <algorithm> // 用于 sort 和 max 函数
using namespace std;

// 辅助函数：判断 s 是否是 t 的子序列
bool isSubsequence(const string& s, const string& t) {
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == s.length();
}

int findLUSlength(vector<string>& strs) {
    // 按字符串长度从大到小排序
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });

    // 遍历每个字符串
    for (int i = 0; i < strs.size(); i++) {
        bool isSpecial = true;
        // 检查是否是其他字符串的子序列
        for (int j = 0; j < strs.size(); j++) {
            if (i == j) continue; // 不和自己比较
            if (isSubsequence(strs[i], strs[j])) {
                isSpecial = false;
                break;
            }
        }
        // 如果是特殊序列，返回其长度
        if (isSpecial) {
            return strs[i].length();
        }
    }

    // 如果没有特殊序列，返回 -1
    return -1;
}

int main() {
    vector<string> strs1 = {"aba", "cdc", "eae"};
    cout << findLUSlength(strs1) << endl; // 输出: 3

    vector<string> strs2 = {"aaa", "aaa", "aa"};
    cout << findLUSlength(strs2) << endl; // 输出: -1

    vector<string> strs3 = {"aabbcc", "aabbcc", "cb"};
    cout << findLUSlength(strs3) << endl; // 输出: 2

    return 0;
}
