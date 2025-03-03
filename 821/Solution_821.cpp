#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

vector<int> shortestToChar(string str, char c) {
    int n = str.length();
    vector<int> result(n, INT_MAX); // 初始化结果数组
    int prev = -INT_MAX;            // 用于记录上一个字符 c 的位置

    // 从左到右遍历
    for (int i = 0; i < n; i++) {
        if (str[i] == c) {          // 检查当前字符是否为 c
            prev = i;
        }
        result[i] = abs(i - prev);  // 计算当前位置到上一个 c 的距离
    }

    prev = INT_MAX;                 // 重置 prev 为一个很大的值

    // 从右到左遍历
    for (int m = n - 1; m >= 0; m--) {
        if (str[m] == c) {          // 检查当前字符是否为 c
            prev = m;
        }
        result[m] = min(result[m], abs(m - prev)); // 取左右两侧的最小距离
    }

    return result;
}

int main() {
    string s = "loveleetcode";
    char c = 'e';
    vector<int> result = shortestToChar(s, c);

    // 输出结果
    for (int dist : result) {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}

